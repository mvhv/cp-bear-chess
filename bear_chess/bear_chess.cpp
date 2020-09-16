/*
 * pcs_contest2018_1: Bear Chess
 *
 * Maximum Bipartite Matching
 *
 * Decompose the grid into a bipartite graph between row indicies and
 * column indicies such that each grid square is represented as an edge
 * between a row/column pair. Then find max match using simplified
 * ford-flkerson
 */

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
                                
                //augment path
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
    
    //unpack
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


