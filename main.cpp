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

#include <ranges>  // For std::ranges::join_with
#include "Connect4Game.hpp"

using namespace std;
using namespace views;
using namespace ranges;


int main(int, char**){
    vector<vector<char>> mat(6, vector<char>(8, 0));
    Connect4Board board = Connect4Board(mat);
    Connect4Player player1 = Connect4Player('x');
    Connect4Player player2 = Connect4Player('o');
    Connect4WinStrategy winStrat = Connect4WinStrategy();
    vector<Connect4WinStrategy*>  winStrats = {&winStrat};



    Connect4Game game = Connect4Game(&board, &player1, &player2, winStrats);
    game.run();
    if (game.getWinner()){
        cout << game.getWinner()->getPlayerMark() << " WINS" << endl;
    }
    return 0;
}


///  
///   1 coding interview similar to tech screen - debugging excersice  
///   1 sys design and software design - more coding focus using hackerrank with diagrams | not init empty, very high level, less about optz and more about a broader sol
///     - more coding focus?
///   1 behavioral interview - talking about tech background
///      - more complex or diff project i worked on and the impact on the business
///      - self reflection
///      - prioritization
///      - interest in anduril
///   1 team fit interview - non technical vibe check?
///      - collaboration
///      - motivation and growth goals
///      - what I've worked on 


/// vest and camera on
/// prep questions
///  