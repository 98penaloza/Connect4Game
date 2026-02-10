#include "Connect4Game.hpp"

Connect4Game::Connect4Game(Connect4Board *board, Connect4Player *player1, Connect4Player *player2, std::vector<Connect4WinStrategy *> &winStrategies)
    : board(board), player1(player1), player2(player2), winStrategies(winStrategies)
{
}

void Connect4Game::run()
{
  this->curPlayer = this->player1;
  this->gameStatus = GameStatus::IN_PROGRESS;
  this->winner = nullptr;
  while (this->getGameStatus() == GameStatus::IN_PROGRESS)
  {
    bool valid = false;
    int input;
    IBoardMove *move;
    while (!valid)
    {
      input = Console::getInput(curPlayer);
      Connect4BoardMove con4move = Connect4BoardMove(curPlayer->getPlayerMark(), input);
      IBoardMove *move = &con4move;
      valid = this->move(move);
    }

    Console::printBoard(this->board);
    for (auto strategy : winStrategies)
    {
      Connect4BoardMove con4move = Connect4BoardMove(curPlayer->getPlayerMark(), input);
      IBoardMove *move = &con4move;
      if (strategy->checkForWin(this->board, this->curPlayer, move))
      {
        this->winner = this->curPlayer;
        return;
      }
    }
    if (this->board->isBoardFull() || this->getWinner())
    {
      this->gameStatus = GameStatus::FINISHED;
    }
    this->switchPlayer();
  }
}

void Connect4Game::switchPlayer()
{
  this->curPlayer = this->curPlayer == this->player1 ? this->player2 : this->player1;
}

bool Connect4Game::move(IBoardMove *move)
{
  return this->board->makeMove(move);
}

IPlayer *Connect4Game::getWinner()
{
  return this->winner;
}

GameStatus Connect4Game::getGameStatus()
{
  return this->gameStatus;
}
