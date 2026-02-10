#pragma once
#include <string>
#include "IBoard.hpp"
#include "IPlayer.hpp"
class Console{
public:
  static int getInput(IPlayer *player);
  static void printBoard(IBoard*board);
};