#include "Connect4Board.hpp"

Connect4BoardDest::Connect4BoardDest(int row, int column) : row(row), column(column)
{
}

bool Connect4Board::isColumnFull(int col)
{
  return mat[0][col];
}

Connect4Board::Connect4Board(std::vector<std::vector<char>> &mat) : rows(mat.size()), cols(mat[0].size()), mat(mat)
{
}

bool Connect4Board::makeMove(IBoardMove *move)
{
  Connect4BoardMove *connect4move = dynamic_cast<Connect4BoardMove*>(move);
  int col = connect4move->column;
  if(this->isColumnFull(col) or col < 0 or this->cols <= col){
    return false;
  }
  int row = 0;
  while(row < this->rows and !this->mat[row][col]){
    row ++;
  }
  row --;
  this->mat[row][col] = connect4move->marker;
  return true;
}


bool Connect4Board::isBoardFull()
{
  for(int col = 0 ; col < this->cols ; col++){
    if (!this->isColumnFull(col)){
      return false;
    };
  }
  return true;
}

char Connect4Board::getMarker(IBoardDest *dest)
{
  Connect4BoardDest *destination = dynamic_cast<Connect4BoardDest*>(dest);
  return this->mat[destination->row][destination->column];
}

std::unique_ptr<IBoardSize> Connect4Board::getBoardSize()
{
  return std::make_unique<Connect4BoardSize>(this->rows, this->cols);
}

Connect4BoardSize::Connect4BoardSize(int rows, int columns)
: rows(rows), columns(columns)
{
}

Connect4BoardMove::Connect4BoardMove(char marker, int column):
marker(marker), column(column)
{
}
