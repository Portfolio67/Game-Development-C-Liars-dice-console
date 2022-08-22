//
// Created by Ace Six on 8/8/22.
//

#include <vector>
#include "Game.h"

const std::__1::vector<int> &Game::getTableDice() const {
    return tableDice;
}

void Game::setTableDice(const std::__1::vector<int> &tableDice) {

    Game::tableDice = tableDice;
}

Game::Game(const vector<int> &tableDice) : tableDice(tableDice) {}

Game::~Game() {
}

