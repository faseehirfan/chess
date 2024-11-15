#include "piece.h"

#include "board.h"

using namespace std;

Piece::Piece(PieceType t, Color c, int points, Square* pos, Board *b)
    : points{points}, type{t}, color{c}, pos{pos}, board{b} {}

// gets linear moves possible
void Piece::getlinearMoves(int row, int col, vector<Move>& moves) const {
  int currentRow = pos->getRow();
  int currentCol = pos->getCol();
  int newRow = currentRow + row;
  int newCol = currentCol + col;

  while (newCol >= 0 && newCol < 8 && newRow >= 0 && newRow < 8) {
    // logic for checking moves.
    Piece* oldPiece = board->getSquare(newRow, newCol).getPiece();
    if (oldPiece && oldPiece->getColor() != color) {
      moves.push_back(Move{currentRow, currentCol, newRow, newCol});
      break;
    }
    if (oldPiece && oldPiece->getColor() == color){
      break;
    }

    moves.push_back(Move{currentRow, currentCol, newRow, newCol});
    newRow += row;
    newCol += col;
  }
}

// check if piece can check king
bool Piece::canCheck() const {
  vector<Move> moves = getMoves();
  for (auto move : moves) {
    Piece* currentPiece = board->getSquare(move.nr, move.nc).getPiece();
    if (currentPiece && currentPiece->getType() == PieceType::King &&
        currentPiece->getColor() != color) {
      return true;
    }
  }
  return false;
}

Color Piece::getColor() const { 
  if (this == nullptr) {
    return Color::NoColor;
  }
  return color; 
}

PieceType Piece::getType() const {
  if (this == nullptr) {
    return PieceType::NoPiece;
  }
  return type;
}

int Piece::getPoints() const { return points; }

void Piece::updateSquare(Square* s) { pos = s; }

Piece::~Piece() {}
