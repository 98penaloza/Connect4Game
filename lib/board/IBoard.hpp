#pragma once
#include <memory>
struct IBoardMove
{
    virtual ~IBoardMove() = default;
};
struct IBoardDest
{
    virtual ~IBoardDest() = default;
};

struct IBoardSize
{
    virtual ~IBoardSize() = default;
};

class IBoard
{

public:
    ~IBoard() = default;
    virtual bool makeMove(IBoardMove *move) = 0;
    virtual bool isBoardFull() = 0;
    virtual char getMarker(IBoardDest *dest) = 0;
    virtual std::unique_ptr<IBoardSize> getBoardSize() = 0;
};