# Bear Chess
## Expected Solution

The bounds of this problem were chosen to allow three successively more efficient solutions.

The small case of ~(1 /leq R, C /leq 7)~ can be solved with a complete search with reasonable pruning. A pure brute force trying all combinations of rooks in all spaces would not complete, with a time complexity of ~O(2^(R*C))~. By noting that any row or column can only contain one rook at max, the search can be reduced to ~O(R^C)~ by only trying one rook for each column, and further reduced to ~O(max(R, C)!)~ by also excluding a row once a rook has been assigned to it.

The medium case of ~(1 /leq R, C /leq 15)~ can be solved with a DP. By defining the state space of our solution to be a suffix of rows, and a set of columns that been attacked, a recurrance relation can be constructed such that the optimal solution is defined in terms of an optimal solution from row ~0~ to ~R-1~.

The large case of ~(1 /leq R, C /leq 100)~ is deceptively simple and requires similar observations to the brute-force. Any square on the board can be represented by its ~(i,j)~ coordinate, and subsequently can be considered as a relation between a row and a column. This makes it easy to construct a [bipartite graph](https://en.wikipedia.org/wiki/Bipartite_graph) mapping from row index to column index with with edges representing squares on the board. Edges representing soiled squares can be removed from the graph. Noting that if two edges share a node, they represent squares that lie on the same column or row, and are thus rooks placed at those locations are able to attack each other. The problem is then reduced to finding the largest set of edges that do not share a node, known as a [matching.](https://en.wikipedia.org/wiki/Matching_(graph_theory))

This can be achieved by applying a simplified version of the Ford-Fulkerson algorithm for calculating [max-flow](https://en.wikipedia.org/wiki/Maximum_flow_problem) in a graph, as bipartite-matching is a special case of max-flow. For each possible row, a DFS is performed to determine if it has a valid edge to a column. For each edge that edge is valid (a square with no honey) if the column has not already been taken the edge is added to the solution, and the number of matches is increased by one. Alternatively, if the column has already been taken by another row, then the DFS continues to see if the occupying row has an alternative valid match. This continues recursively until all rows have been investigated, and the final result is returned.

The below code is an example implementation of this:

```cpp
#include <bits/stdc++.h>
using namespace std;

int T, R, C, dirty;

/*
 * Return true if augmenting path exists and record it
 * */
bool isAugPath(vector<vector<bool> > &graph, int row,
               vector<bool> &visited, vector<int> &matches) {

    //try all cols for row
    for (int col = 0; col < C; ++col) {
        //if square clean and col unvisited
        if (graph[row][col] && !visited[col]) {
            
            //mark as visited
            visited[col] = true;

            //if col not assigned, or prev assigned row has
            //alternative col, then path can be augmented
            if (matches[col] < 0 ||
                isAugPath(graph, matches[col], visited, matches)) {
                matches[col] = row;
                return true;
            }
        }
    }
    return false;
}

/*
 * Return maximum possible number of matchings
 */
int maxBPMatch(vector<vector<bool> > &graph) {
        
    //record row matches by col, -1 indicates no match
    vector<int> matches(C, -1);

    int matching = 0;

    for (int row = 0; row < R; ++row) {
        //all cols start unseen to each row
        vector<bool> visited(C, false);

        //if aug path exists, record and count matching
        if (isAugPath(graph, row, visited, matches)) {
            matching++;
        }
    }
    return matching;
}

int testCase() {

    cin >> R >> C;

    //build bp graph of non-excluded squares
    vector<vector<bool> > graph(R, vector<bool>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> dirty;
            graph[i][j] = (!dirty);
        }
    }
    return maxBPMatch(graph);
}

int main() {

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cout << testCase() << '\n';
    }
}
```

