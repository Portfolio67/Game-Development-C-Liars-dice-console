//Title: file-reader.cpp
// Name: Shane Flaten
// Course: IT-312-J6014 Software Devel w/C++.Net 22EW&
// Date: Aug-7-2022
//Project number: 6-3

//This Program keeps track of the scores after each round.
// The program  allows reads a text file.

#include "Player.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

//PLAYERS INFO
string Player::getName() const{
    return name;
}
void Player::setName(string name) {
    Player::name = name;
}


//ROLL SCORE
int Player::getScore() const {
    return score;
}
void Player::setScore(int iScore) {
    Player::score = iScore;
}


// WINS
int Player::getWins() const {
    return wins;
}

void Player::setWins(int wins1) {
    Player::wins = wins1;
}

void Player::putData() const {
    //cout << score << " ";
    string goesFirst;
    if (score == 0){
        goesFirst = " You are not the first guesser.";
    }
    if (score == 1) {
        goesFirst = " YOU GET THE FIRST GUESS NEXT TIME";
    }
    cout << "Player Name: "<< name << " ";
    cout << endl;
    cout << "Player wins: "<< wins << endl;
    cout << name << goesFirst << endl;
}

void Player::setDice(vector<int> vector1) {
    dice = vector1;
}

const vector<int>& Player::getDice() const{
    return dice;
}

