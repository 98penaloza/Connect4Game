#pragma once

#include "IWinStrategy.hpp"
#include <Connect4Player.hpp>
#include <Connect4Board.hpp>

class Connect4WinStrategy : public IWinStrategy
{
public:
  bool checkForWin(IBoard *board, IPlayer *player, IBoardMove *move) override;
private:
  bool checkForWinDiag(IBoard *board, IPlayer *player, int row, int col);
  bool checkForWinRow(IBoard *board, IPlayer *player, int row, int col);
  bool checkForWinCol(IBoard *board, IPlayer *player, int row, int col);
};