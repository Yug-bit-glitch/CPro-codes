TWIXT LITE – BY YUG PATEL

1)RULES AND REGULATIONS OF TWIXT

The board size is 24×24 with the 4 corner holes removed

Player A connects the top border (row 0) to the bottom border (row 23)

Player B connects the left border (column 0) to the right border (column 23)

Players are allowed to place pins on their own borders

Players cannot place pins on the opponent's borders

A move is valid only if the cell is empty and follows the rules

The first player to create a continuous path between their two opposite sides wins

2)STRUCTURE OF IMPLEMENTATION

control.c

twixt.h

winchecking.h

board.c

winchecking.c

game.txt

Makefile

README.md

3)INFORMATION

Player A is Red

Player B is Blue

The last active game is saved in game.txt

The saved game can be loaded when the program starts again

3)FEATURES

Full 24×24 Twixt board with corner restrictions

Input validation according to game rules

Automatic win detection for both players

Save and load system using game.txt

Simple command-line interface with color display

Modular code separated into board, control, and win-checking files


4)HOW TO PLAY

The game has two players: A (Red) and B (Blue)

Player A always plays first

Players enter row and column numbers to place a pin

A move is accepted only if the position is empty and valid

Player A must connect the top border to the bottom border

Player B must connect the left border to the right border

The board updates after every move

The first player to complete a connected path wins

At startup, the user can choose to load the previous saved game

5)COMPILATION

Manual Compilation:

gcc board.o winchecking.o control.o -o twixt

./twixt

Using Makefile:

make

./twixt

TO RESPECTED TA's
YUG PATEL
2025101081

