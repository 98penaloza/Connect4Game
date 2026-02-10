#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <vector>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <format>
#include <bits/stdc++.h>

#include <ranges> // For std::ranges::join_with
#include "Connect4Game.hpp"

using namespace std;
using namespace views;
using namespace ranges;

int main(int, char **)
{
    vector<vector<char>> mat(6, vector<char>(8, 0));
    Connect4Board board = Connect4Board(mat);
    Connect4Player player1 = Connect4Player('x');
    Connect4Player player2 = Connect4Player('o');
    Connect4WinStrategy winStrat = Connect4WinStrategy();
    vector<Connect4WinStrategy *> winStrats = {&winStrat};

    Connect4Game game = Connect4Game(&board, &player1, &player2, winStrats);
    game.run();
    if (game.getWinner())
    {
        cout << game.getWinner()->getPlayerMark() << " WINS" << endl;
    }
    return 0;
}