#include "Console.hpp"
#include <iostream>
#include "Connect4Board.hpp"

int Console::getInput(IPlayer *player)
{
  std::cout << "Enter col number for " << player->getPlayerMark() << ":" << std::endl;
  int value;
  std::cin >> value;
  return value;
}

void Console::printBoard(IBoard *board)
{
  auto size = board->getBoardSize();
  Connect4BoardSize *boardSize = dynamic_cast<Connect4BoardSize *>(size.get());
  for (int row = 0; row < boardSize->rows; row++)
  {
    for (int col = 0; col < boardSize->columns; col++)
    {
      Connect4BoardDest destination = Connect4BoardDest(row, col);
      IBoardDest *dest = &destination;
      char marker = board->getMarker(dest);
      if (!marker)
      {
        marker = ' ';
      }
      std::cout << "|" << marker << "|" << "\t";
    }
    std::cout << std::endl;
  }
}
