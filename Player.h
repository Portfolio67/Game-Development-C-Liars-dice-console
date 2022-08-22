

#ifndef WRITE_TO_FILE_PLAYER_H
#define WRITE_TO_FILE_PLAYER_H
#include <string>
#include <vector>
using namespace std;

class Player {
public:
    int wins;
    int getWins() const;
    void setWins(int wins);

    string name;
    string getName() const;
    void setName(string name);

    int score;
    int getScore() const;
    void setScore(int i);

    void putData() const;
    vector<int> dice;

    void setDice(vector<int> vector1);
    const vector<int>& getDice() const;
};


#endif //WRITE_TO_FILE_PLAYER_H
