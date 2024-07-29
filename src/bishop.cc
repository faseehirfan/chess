#include "bishop.h"

Bishop::Bishop(Color c, Square *pos, Board *b) 
    : Piece{PieceType::Bishop, c, 3, pos, b} {}

vector<Move> Bishop::getMoves() const {
    vector<Move> moves;
    if (!pos) return moves;

    int currentRow = pos->getRow();
    int currentCol = pos->getCol();

    // diagonal movement
    getlinearMoves(1, 1, moves);
    getlinearMoves(1, -1, moves);
    getlinearMoves(-1, 1, moves);
    getlinearMoves(-1, -1, moves);

    return moves;
}