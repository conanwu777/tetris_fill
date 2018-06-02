# tetris_fill
A simple program to find the smallest square board where a given set of tetris pieces can be placed into.

This project done in collaboration with Ezra Maize at 42.
We implemented a simple backtracking algorithm which orders the possible positions of each given piece on the board in a linked list and increase the board size when a solution cannot be found.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```
