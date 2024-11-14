# chess
CS247 Spring 2024 Final Project

## To Run

### Instructions to Compile and Run the Chess Program

1. **Navigate to the `src` directory:**
   First, change to the directory containing your source files and `Makefile`:
   ```bash
   cd src
   ```

2. **Compile the program:**
   Use the `make` command to compile the source files and generate the executable:
   ```bash
   make
   ```

3. **Run the executable:**
   Once the compilation is complete, you can run the program by executing the following command:
   ```bash
   ./chess
   ```

4. **Clean up the compiled files (optional):**
   If you want to remove the compiled executable and object files, use the `make clean` command:
   ```bash
   make clean
   ```


## Commands

- `game white-player black-player` starts a new game. The parameters white-player and black-player
can be either human or computer[1-4].

- `resign` concedes the game to your opponent. This is the only way, outside of winning or drawing the game, to end a
game.
-  A move consists of the command `move`, followed by the starting and ending coordinates of the piece to be moved. For
example: `move e2 e4`. Castling would specified by the two-square move for the king: `move e1 g1` or `move e1
c1` for white. Pawn promotion would additionally specify the piece type to which the pawn is promoted: move e7
Q. In the case of a computer player, the command move (without arguments) makes the computer player make a
e8 move.

- `setup` enters setup mode, within which you can set up your own initial board configuration (starting from an empty board). This can only be done when a game is not currently running. Within setup mode, the following language is used:
  
  1. `+ K e1` places the piece K (i.e., white king in this case) on the square e1. If a piece is already on that square, it is replaced. The board should be redisplayed.
  2. `- e1` removes the piece from the square e1 and then redisplays the board. If there is no piece at that square, take no action.

- `= colour` makes it colour’s turn to go next.
- `done` leaves setup mode.

## UML
![AD_4nXcfxyXXvwAhh-Td5L_UjX5FoBy6UUzXg9mzCvhDZWAt5j0h-UP6N1d2lsRW4PN4c6Vf7b4usUj8qwxy_dvy4OOTHUXeg3lrZV9e3pen93C6-j2ILs-TolN6](https://github.com/user-attachments/assets/3b424598-6e64-46eb-ad89-6ada299bc8ca)

## Key Features
The key features that we have implemented into our chess game are as follows:

### 1) Chess Game Mechanics
- Piece Movement: We developed the game mechanics so that each type of piece (Pawn, Rook, Bishop, Knight, Queen, and King) follows the standard rules in chess.
- Special Movement: Our implementation allows users to perform moves such as en passant, castling, and pawn promotion.
- Check Detection: The game can detect checks and prevents users from making moves that result in themselves getting checked.
- Checkmate/Stalemate Detection: The game can detect scenarios in which a checkmate or stalemate is reached and updates the score accordingly.
- Multiplayer Logic: We implemented game logic that manages turn-taking between two players, and also incorporated a scoring system.
  
### 2) CLI Commands
- Simple Commands: Users are able to interact with and use the program using simple commands through the text-based interface.
- Custom Setup: Players are also able to play the game using a customized board, where each player chooses the pieces and their locations on the board.
- Text and Graphics-based Displays
- Text-based Display: We effectively implemented a visually clear text-based display and interface, allowing the player to play chess in the command line environment.
- Graphics-based Display: We created a graphical interface using X11 with pieces represented as letters, improving the players’ experience from the text-based display.
  
### 3) Non-Human Player
- Computer Player: The game includes move generation logic to allow human players to play against computer players of varying difficulties.
- Multi-level Options: We implemented four difficulty levels for the computer player, each with more sophisticated move generation than the last:
- Level One: Random valid move from a random piece is chosen.
- Level Two: Prioritizes capturing moves and checks over other moves.
- Level Three: Prioritizes avoiding capture, capturing moves, and checks.
- Level Four: Prioritizes capturing moves that capture pieces worth a higher number of points, avoiding capture, and checks.

### 4) Error Handling
- Error Consideration: We considered cases where errors may arise and make sure that the program effectively and appropriately handles all errors.
- Testing: Our group produced both unit tests and integration tests for every case (including edge cases) to ensure that our program covered all possibilities.
- Extra Credit Features
- Undo Move: The game allows for an unlimited number of undos until the starting state of the board, while managing the turn system accordingly. 
