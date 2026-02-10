#pragma once
#include "IPlayer.hpp"

class Connect4Player : public IPlayer
{
private:
    char mark;

public:
    Connect4Player(char mark);
    char getPlayerMark() override;
};
