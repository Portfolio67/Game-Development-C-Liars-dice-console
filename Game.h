//
// Created by Ace Six on 8/8/22.
//

#ifndef WRITE_TO_FILE_GAME_H
#define WRITE_TO_FILE_GAME_H
using namespace std;
#include <vector>

class Game {
public:
    vector<int> tableDice;

    virtual ~Game();

    Game(const vector<int> &tableDice);

    const vector<int> &getTableDice() const;

    void setTableDice(const vector<int> &tableDice);

};

#endif //WRITE_TO_FILE_GAME_H
