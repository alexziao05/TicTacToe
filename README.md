# Tic Tac Toe Game

A command-line implementation of the classic Tic Tac Toe game written in C++.

## Description

This is a two-player Tic Tac Toe game where players take turns placing X's and O's on a 3x3 grid. The first player to get three of their marks in a row (horizontally, vertically, or diagonally) wins the game. If all spaces are filled without a winner, the game ends in a draw.

## Features

- Interactive command-line gameplay
- Input validation (prevents invalid moves and occupied spaces)
- Automatic turn switching between Player X and Player O
- Win detection for rows, columns, and diagonals
- Draw detection when board is full
- Clear game board display with numbered positions (1-9)

## How to Play

1. The game starts with Player X
2. Players take turns entering a number (1-9) corresponding to the position on the board:
   ```
   1 2 3
   4 5 6
   7 8 9
   ```
3. The game will display the updated board after each move
4. The first player to get three marks in a row wins
5. If all spaces are filled without a winner, the game is a draw

## Compilation and Running

### Prerequisites
- A C++ compiler (g++, clang++, etc.)
- C++11 or later

### Compile
```bash
g++ -o tictactoe tictactoe.cpp
```

### Run
```bash
./tictactoe
```

## Game Rules

- Players alternate turns, starting with Player X
- Choose a position by entering a number from 1-9
- Positions correspond to the grid layout shown above
- You cannot place a mark on an already occupied space
- Win by getting three marks in a row (horizontal, vertical, or diagonal)
- Game ends in a draw if all spaces are filled with no winner

## Project Structure

```
TicTacToe/
├── README.md           # This file
└── tictactoe.cpp      # Main game source code
```

## Author

Alex Huang

## License

This project is open source and available under the MIT License.
