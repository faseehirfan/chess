#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <vector>

class Bishop : public Piece {
  private:

  public:
    Bishop(Color c, Square *pos);
    vector<Move> getMoves() const override;
};

#endif
