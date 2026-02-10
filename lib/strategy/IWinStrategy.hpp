#pragma once
#include "IBoard.hpp"
#include "IPlayer.hpp"

class IWinStrategy {
public:
    ~IWinStrategy() = default;
    virtual bool checkForWin(IBoard *board, IPlayer *player, IBoardMove *move) = 0;
};