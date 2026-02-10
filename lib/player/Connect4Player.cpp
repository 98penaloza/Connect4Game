#include "Connect4Player.hpp"

Connect4Player::Connect4Player(char mark) : mark(mark)
{
}

char Connect4Player::getPlayerMark()
{
    return this->mark;
}
