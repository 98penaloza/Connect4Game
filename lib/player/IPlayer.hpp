#pragma once
class IPlayer
{
public:
    virtual ~IPlayer() = default;
    virtual char getPlayerMark() = 0;
};
