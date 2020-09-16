Yogi "Gozz" Bear, being smarter than the average bear, is attempting to develop his own unique take on chess. Although, still being a bear, he only has access to a checkerboard pic-a-nic blanket with ~R~ rows, and ~C~ columns, and his pristine collection of stolen rooks (castles).

Gozz wishes to find the ideal starting position for his game, such that he can place as many rooks as possible onto the checkerboard blanket without allowing any two pieces to attack each other directly.

Unfortunately, during one of his debaucherous bear adventures Gozz stumbled home in a daze and has splattered honey all over his beautiful pic-a-nic blanket. Not wanting to get his shiny rooks sticky, he has decided to exclude the soiled squares of his blanket from the game. Please help Gozz figure out the maximum number of pieces he can place onto his blanket without putting any in danger, or placing any onto a sticky square.

NOTE: Rooks, are a standard chess piece that are able to move any number of squares along the four cardinal directions. They may move and attack in a line up, down, left or right, but may not move diagonally. Rooks may still attack even if there is a sticky square between the pieces.

Input Specification
-------------------
The first line contains a single integer ~T~, the number of test cases to follow. Each test case begins with a line containing two space separated integers ~R~ and ~C~, the number of rows and columns of the checkerboard blanket respectively. Then follows ~R~ lines each containing ~C~ space separated integers. The ~i~-th integer on the ~j~-th line indicating the state of the square at position ~(i, j)~, with `1` indicating a soiled square and `0` indicating a clean square.

Output Specification
--------------------
For each test case, output a line containing a single integer, the maximum number of rooks that Gozz could place according to his rules.

Bounds
------
Note this problem includes sub-problems of increasing difficulty worth different numbers of points:
- 10 points: ~1 \leq R,C \leq 7~
- 20 points: ~1 \leq R,C \leq 15~
- 70 points: ~1 \leq R,C \leq 100~

For all sub-problems:
- ~1 \leq T \leq 10~

Sample Input
------------
    1
    3 3
    0 0 0
    1 0 0
    1 0 0

Sample Output
-------------
    3
