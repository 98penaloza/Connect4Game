#pragma once
#include "IGame.hpp"
#include "IPlayer.hpp"
#include "Connect4Board.hpp"
#include "Connect4Player.hpp"
#include "Connect4WinStrategy.hpp"
#include <vector>
#include <Console.hpp>



class Connect4Game : public IGame
{
public:
  Connect4Game(Connect4Board*board, Connect4Player*player1, Connect4Player*player2, std::vector<Connect4WinStrategy*> &winStrategies);
  void run() override;
  void switchPlayer() override;
  bool move(IBoardMove *move) override;
  IPlayer *getWinner() override;
  GameStatus getGameStatus() override;
private:
  Connect4Board *board;
  Connect4Player *player1;
  Connect4Player *player2;
  Connect4Player *curPlayer;
  Connect4Player *winner;
  GameStatus gameStatus;
  std::vector<Connect4WinStrategy*> winStrategies;
};