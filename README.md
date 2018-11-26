# Conway's Game of Life

C++ implementation for Conway's Game of Life.
Training for c++ and ncurses library.

![alt text](http://www.wikizeroo.net/index.php?q=aHR0cHM6Ly91cGxvYWQud2lraW1lZGlhLm9yZy93aWtpcGVkaWEvZW4vNC80NS9SdWxlc19vZl9Db253YXklMjdzX2dhbWVfb2ZfbGlmZV8tX0dsaWRlci5naWY "Example Pattern")

# Rules of Conway's Game of Life  
  The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1- Any live cell with fewer than two live neighbors dies, as if by underpopulation.
2- Any live cell with two or three live neighbors lives on to the next generation.
3- Any live cell with more than three live neighbors dies, as if by overpopulation.
4- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
