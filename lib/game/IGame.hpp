#pragma once

#include <string>
#include "IPlayer.hpp"
#include "IBoard.hpp"

enum GameStatus {
    NOT_STARTED,
    IN_PROGRESS,
    FINISHED,
};

class IGame{
    public:
        ~IGame() = default;
        virtual void run() = 0;
        virtual bool move(IBoardMove *move) = 0;
        virtual IPlayer* getWinner() = 0;
        virtual GameStatus getGameStatus() = 0;
        virtual void switchPlayer() = 0;
};