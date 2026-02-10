#pragma once
#include "IBoard.hpp"
#include <vector>

struct Connect4BoardMove : IBoardMove
{
  char marker;
  int column;
  Connect4BoardMove(char marker, int column);
};
struct Connect4BoardDest : IBoardDest
{
  int row;
  int column;
  Connect4BoardDest(int row, int column);
};

struct Connect4BoardSize : IBoardSize
{
  int rows;
  int columns;
  Connect4BoardSize(int rows, int columns);
};


class Connect4Board : public IBoard
{
private:
  int rows;
  int cols;
  std::vector<std::vector<char>> mat;
  bool isColumnFull(int col);

public:
  Connect4Board(std::vector<std::vector<char>> &mat);
  bool makeMove(IBoardMove *move) override;
  bool isBoardFull() override;
  char getMarker(IBoardDest *dest) override;
  std::unique_ptr<IBoardSize> getBoardSize() override;
};