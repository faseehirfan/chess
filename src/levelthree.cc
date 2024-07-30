#include "levelthree.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


LevelThree::LevelThree(Color c, Board *b) : Computer{c, b} {}

Move LevelThree::getMove() {
    std::vector<Move> avoidingCaptureMoves;
    std::vector<Move> capturingMoves;
    std::vector<Move> checkingMoves;
    std::vector<Move> otherMoves;

    // Iterate through all the pieces of the given color
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = board->getSquare(row, col).getPiece();
            if (piece && piece->getColor() == color) {
                std::vector<Move> moves = piece->getMoves();
                for (const Move& move : moves) {
                    Piece* targetPiece = board->getSquare(move.nr, move.nc).getPiece();

                    Move turn {move.r, move.c, move.nr, move.nc};

                    if(!board->canMove(turn, color)){
                        continue;
                    }

                    // Make a temporary move
                    board->move(turn);

                    bool isCheck = board->isCheck((color == Color::White) ? Color::Black : Color::White);

                    // Check if the move avoids capture
                    bool avoidsCapture = true;
                    for (int oppRow = 0; oppRow < 8; ++oppRow) {
                        for (int oppCol = 0; oppCol < 8; ++oppCol) {
                            Piece* oppPiece = board->getSquare(oppRow, oppCol).getPiece();
                            if (oppPiece && oppPiece->getColor() != color) {
                                std::vector<Move> oppMoves = oppPiece->getMoves();
                                for (const Move& oppMove : oppMoves) {
                                    if (oppMove.nr == move.nr && oppMove.nc == move.nc) {
                                        avoidsCapture = false;
                                        break;
                                    }
                                }
                            }
                        }
                        if (!avoidsCapture) break;
                    }

                    // Undo the move
                    board->undoMove();

                    // Categorize moves
                    if (avoidsCapture) {
                        avoidingCaptureMoves.push_back(move);
                    } else if (targetPiece && targetPiece->getColor() != color) {
                        capturingMoves.push_back(move);
                    } else if (isCheck) {
                        checkingMoves.push_back(move);
                    } else {
                        otherMoves.push_back(move);
                    }
                }
            }
        }
    }

    // Choose a move based on the priority
    if (!avoidingCaptureMoves.empty()) {
        return avoidingCaptureMoves.front();
    } else if (!checkingMoves.empty()) {
        return checkingMoves.front();
    } else if (!capturingMoves.empty()) {
        return capturingMoves.front();
    } else if (!otherMoves.empty()) {
        return otherMoves.front();
    } else {
        throw std::runtime_error("No valid moves available"); // Handle no valid move scenario
    }
}
