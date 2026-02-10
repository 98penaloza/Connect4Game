#include "Connect4WinStrategy.hpp"
#include <algorithm>



bool Connect4WinStrategy::checkForWin(IBoard *board, IPlayer *player, IBoardMove *move)
{
  auto size = board->getBoardSize();
  Connect4BoardSize *boardSize = dynamic_cast<Connect4BoardSize*>(size.get());
  
  Connect4BoardMove *connect4move = dynamic_cast<Connect4BoardMove *>(move);
  int row = 0;
  while(row < boardSize->rows){
    auto destination = Connect4BoardDest(row, connect4move->column);
    IBoardDest *dest = &destination;
    char marker = board->getMarker(dest);
    if (marker == player->getPlayerMark()){
      break;
    }
    row++;
  }
  return this->checkForWinCol(board, player, row, connect4move->column) ||
         this->checkForWinRow(board, player, row, connect4move->column) ||
         this->checkForWinDiag(board, player, row, connect4move->column);
}

bool Connect4WinStrategy::checkForWinDiag(IBoard *board, IPlayer *player, int row, int col)
{
  return false;
}

bool Connect4WinStrategy::checkForWinRow(IBoard *board, IPlayer *player, int row, int col)
{
  auto size = board->getBoardSize();
  Connect4BoardSize *boardSize = dynamic_cast<Connect4BoardSize *>(size.get());
  
  int counter = 0;
  col = std::max(0,col-3);
  int maxcol = std::min(boardSize->columns, col+4);
  
  for(;col < maxcol;col++){
    auto destination = Connect4BoardDest(row, col);
     IBoardDest *dest = &destination;
     char marker = board->getMarker(dest);
    if (marker==player->getPlayerMark()){
      counter ++;
    } else {
      counter = 0;
    }
    if (counter == 4){
      return true;
    }
  }
  return false;
}

bool Connect4WinStrategy::checkForWinCol(IBoard *board, IPlayer *player, int row, int col)
{
  auto size = board->getBoardSize();
  Connect4BoardSize *boardSize = dynamic_cast<Connect4BoardSize *>(size.get());
  
  int counter = 0;
  int maxrow = std::min(row+4, boardSize->rows);
  
  for(; row < maxrow ; row++){
    auto destination = Connect4BoardDest(row, col);
    IBoardDest *dest = &destination;
    char marker = board->getMarker(dest);
    if(marker == player->getPlayerMark()){
      counter ++;
    } else {
      break;
    }
  }
  return (counter == 4);
}
