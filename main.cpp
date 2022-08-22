//Title: IT-312_Final_Liars-Dice_S.Flaten.cpp
// Name: Shane Flaten
// Course: IT-312-J6014 Software Devel w/C++.Net 22EW&
// Date: Aug-14-2022
//Project number: FINAL

//　What this program does
/*
 Liar
-First the program asks if you want to test. If so, all the testing functions become true and so you see
 more console output.

-The program uses a low and high parameter to pass to an input validation function for user input.
 For the Booleans the highest parameter is one and lowest is zero.

-The program then reads a text file to the console if one exists.

-The program asks for how many players, stores this number that’s later used to build an array of player
 objects and iterate through for loops.

-The program then calculates the max number of dice that will be on the table and the max number of days
 per face value for validation.

-A player object is initialized to the size of number of players in Array of players.

-The program then goes into a small four loop and prints out the players name and sets that name to an object.
 Everyone rolls dice (in the rollDice function) to determine who goes first by adding five dice.
 The total score of the first role is set from the vector sum and set in the object that later will be
 used to go through the object and find the highest player.

-The Program asks how many games with the highest parameter as 100 games and returns from the validation
 function the game size. Later in the do while loop.

-The program then goes into a 4 loop through the whole player array gets the score of the player and
 pushes the highest player score to the beginning of the Player array.

-Then loops through the whole player array gets the score of the player to zero as a Boolean.

-The first player in the Player array gets assigned a score of one used for a Boolean output for
 the users to see who goes first in guessing.

-The program then goes into the first level of a Game do while loop with two conditions one being
 the number of games that was chosen by the players and if the players decided to quit all the
 games they’ve decided to play.

-In the do while loop there is vector of the table dice which is populated by a four loop.
  The for loop goes through all the users who roll dice through a separate function and their dice is set to the
 object of player and pushed to the back of the table dice vector that is used to build the game object with a default
 constructor. This for loop runs every time a game (and created) is played where everyone has to re-roll.

-The program then sets the table dice vector into the game object which gets destroyed after each game.

-The program then builds a map object and populates it with initial values of zero.
The map which uses a binary search tree, is fast and efficient.

-The program then enters second level do while loop which will go through a guessing round through
 every single player in a nested for loop and go back around through every single player until a
 liar is called. This activated the false Boolean condition to keep guessing. The second condition
 is if a liar is called.

-The For loop (guessing loop) gives each player an option to view their own dice (as the table dice is hidden)
 and the map object which keeps track of guesses and only allows certain guesses to be made by
 calling the input Validation function. The dice the player chooses is used to call the find method of the
 map object and retrieves the value of that key. The key:value will return from the map the lowest possible
 value they can guess, for that dice.

-After a guess is made the whole map is re-populated with two range loops that use the players guessed dice
 (key-value) to split the map into two ranges that will be iterated. A low range and high range based
 on the user’s key. The LOW range get plus one higher than the players guess. The HIGH range get plus zero
 higher than the players guess. NOTE the validation on players guess requires one die count higher than on the map.

-After a guess is made and the map populated the program asks if a liar is called.

-When a liar is called, the for loop ranges out to max (the incrementor is maxed) and the bool
 becomes false for that game. And the program is in the first GAME Do While loop.
The table dice is shown

-The program sets the player who called liar and sets the current player by finding them in a for
 loop going through the array.

-The program gets the Game object table dice vector and uses a counter in a for each loop to count the
 occurrences of the key that the current player guessed on.

-Two if statements check the condition of the count in table dice matches the guessed dice.
 If not a match the Challenger wins. Get wins and one and set wins for challenger,
 then place the first in the array of player, and sets the score Boolean to 1. The same happens for
 the current player in the event the vector count matches their guess.

-A printout of all players data and a new game continues unless the quit Boolean is false
 from user input OR the game incrementor is zero.

 * */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Player.h"
#include "Game.h"
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

// size of all players in the Player array of objects and number of rounds played
int size;
int gameSize;

// used for developer testing
bool testingInProgress;

// Functions used
vector<int> rollDice();
void ReadFile();
unsigned int checkValidInput(int param1, int param2);
void printDice(std::vector<int> &vector1); // call by reference keeps from having to re-make vactor

int main()
{
    // :::::::::: TESTING INIT :::::::::::::::::::::::::::::::::::::::
    int lowBool = 0;
    int highBool = 1;
    cout << "Welcome do you want to test this program? type 1 for yes 0 for no "<< endl;
    testingInProgress = checkValidInput(lowBool, highBool);
    int loopLocation1 = 0;
    int loopLocation2 = 0;

    // READ TEXT FILE TO CONSOLE
    ReadFile();

    //VARIABLES
    string name;
    unsigned int num; // GLOBAL NUMBER OF PLAYERS
    int maxGuessAllowed;
    int numberOfDice = 5;
    int numberOfTotalDiceInPlay; // for highest dice count

    // Get number of players
    int param1 = 2;
    int param2 = 15; // this can be any higher number per rules
    cout << "Welcome Liars, how many players?: "<< endl;
    num = checkValidInput(param1, param2);
    cout << "The number of players is: "<< num << endl;
    size = num; // size used to iterate over for loops of players

    //Find max number of dice that could possibly be guessed Used for the highest guess allowed.
    numberOfTotalDiceInPlay = num * numberOfDice; //five dice per person
    maxGuessAllowed = numberOfTotalDiceInPlay; // for highest possible guess for a dice face value

    // Init Object array and build empty container, an array of Player objects
    Player p[size];
    //vector<Player> p(size);

    // ::::: FIND FIRST GUESSER FOR ROUND ONE ::::::::::::::::
    // Build Players and roll initial roll // Iterate over all player in the Player array of objects
    for(int i = 0; i < size; i++)
    {
        int playerNumber;
        playerNumber = i + 1;
        //user input
        std::cout << "Enter Player name for player # " << playerNumber << endl;
        std::cin >> name;
        p[i].setName(name);

        // get dice rolls
        int count;
        vector<int> initRoll;
        initRoll = rollDice();
        count = accumulate(initRoll .begin(),initRoll .end(),0);

        //print dice results
        std::cout << p[i].getName() << " Your score is " << count << endl;
        // Set players data
        p[i].setScore(count);
        p[i].setWins(0);
        //Add to game data
    }

    // Get number of games  this number will decrement in the outermost do while loop to end the game
    unsigned int numGames;

    // these are for passing to the valid input as parameters
    int lowParam1 = 1;
    int highParam2 = 100; // this can be any higher number per rules

    //user input
    cout << "How many games?: "<< endl;
    numGames = checkValidInput(lowParam1, highParam2); // Check valid input takes
    gameSize = numGames;
    cout << "The number of games is: "<< gameSize << endl;

    //:::::::::::::::::SET WHO GOES FIRST IN THE ARRAY:::::::::::
    //::::  RE-ARRANGES THE PLAYER ARRAY TO START WITH THE FIRST  ::::
    for(int k = 0; k < size; k++) {
        if (p[0].getScore() < p[k].getScore()) {
            p[0] = p[k]; // places winner as the first person to go
            //p[0].setScore(1);
        }
    }

    //::::  RESETS ALL THE SCORES TO ZERO  ::::
    for(int kk = 0; kk < size; kk++){
        p[kk].setScore(0);
    }

    // SET A BINARY ONE TO PRINT WHO GOES FORST
    p[0].setScore(1);


    // Prints players data and order
    for (int t = 0; t < size; t++) {
        p[t].putData();
        cout << endl;
    }

    //:::::::::::::::::::::::::::::::::::::::::::::::::::
    //::::  MAIN LOOP GOES UNTIL END OF USER WISHES ::::
    //:::::::::::::::::::::::::::::::::::::::::::::::::::
    // The bool keepPlaying checks against playAgain user Input and NumGames decrement
    // this tests against the conditions for do while loop to run.
    bool keepPlaying;
    int playAgain;

    do {
        //********************TESTING AREA**********************
        if (testingInProgress) {
            loopLocation1++;
            cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::LOOP2 TEST::::::::::::::::" << endl;
            cout << "current Game loop is : " << loopLocation1 << endl;
            cout << "::::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
            cout  << endl;
            cout  << endl;
        }
        // DO WHILE LOOP VARIABLES
        keepPlaying = true;
        playAgain = 1;

        //--------------- GET ALL PLAYER ROLLS ---------------
        // FOR EACH GAME THEN  guessing commences -Iterate over all player in the Player array of objects
        vector<int> currentRoundDice ; // length is 5 * number of players
        for(int i = 0; i < size; i++)
        {
            //BUILD LOCAL VECTORS TO SORE AND ADD ROLLS
            vector<int> userDice; // length of 5

            //Get dice roll for each player in Player array
            userDice = rollDice();

            cout << p[i].getName() << " Your dice are:  ";
            printDice(userDice);
            cout << endl;

            // SET THE PLAYERS OBJECT DICE
            p[i].setDice(userDice);

            // ADD ALL DICE TO THE all TABLE DICE vector
            int n = 5;
            for (int i = 0; i < n; i++){
                currentRoundDice.push_back(userDice[i]);
            }
        }

//Build game object AND insert an empty vector, (this game object is DeConstructed each time in the do while loop)
        //::::::::::::::::BUILD GAME OBJECT::::::::::::::
        Game game(currentRoundDice);
        // set the game object attributes
        game.setTableDice(currentRoundDice);

        //::::::::::::::::BUILD MAP CONTAINER::::::::::::::
        // Init map object for keeping track og guesses that is remade and zeroed out each round
        map<int, int> allPlayerGuesses; // empty map container  for binary search tree
        allPlayerGuesses.insert(pair<int, int>(1, 0));
        allPlayerGuesses.insert(pair<int, int>(2, 0));
        allPlayerGuesses.insert(pair<int, int>(3, 0));
        allPlayerGuesses.insert(pair<int, int>(4, 0));
        allPlayerGuesses.insert(pair<int, int>(5, 0));
        allPlayerGuesses.insert(pair<int, int>(6, 0));

        // Map iterator variable used to iterate
        map<int, int>::iterator itr;

        //********************TESTING AREA**********************
        if (testingInProgress) {
            cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::MAP MANIPULATION::::::::::::::::" << endl;
            cout << "\nuserGuessedNumOfDice :" << endl;
            cout << "\tKEY\tELEMENT\n";
            for (itr = allPlayerGuesses.begin(); itr != allPlayerGuesses.end(); ++itr) {
                cout << '\t' << itr->first << '\t' << itr->second
                     << '\n';
            }
            // Pre-Existing allKeys 3 : value 3
            // USER MUST GUESS
            //user pics key 5 : ?
            // guess    key 1 : value 4 or higher
            // guess    key 2 : value 4 or higher
            // guess    key 3 : value 4 or higher
            // guess    key 4 : value 4 or higher
            // guess    key 5 : value 4 or higher
            // guess    key 6 : value 3 or higher

            // Pre-Existing allKeys 3 : value 3
            //user pics key 2 : ?  than diceGuessAllowedGreaterThanKey = 4 diceCountAtKey = 3
            // guess    key 1 : value 4 or higher
            // guess    key 2 : value 4 or higher
            // guess    key 3 : value 3 or higher
            // guess    key 4 : value 3 or higher
            // guess    key 5 : value 3 or higher
            // guess    key 6 : value 3 or higher
            std::cout << "numberOfTotalDiceInPlay # " << numberOfTotalDiceInPlay << endl;
            std::cout << "maxGuessAllowed # " << maxGuessAllowed << endl;
            cout << "::::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
            cout  << endl;
            cout  << endl;
        }

        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
        //::::  LIAR INNER LOOP TO GET GUESSES AND FIND A LIAR ::::
        //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        //::::::::::DICE GUESS VARIABLES::::::::
        int userGuessedNumOfDice;
        int userGuessedDie;
        int mapCurrentValue;
        int mapMaxValue_totalDiceType = maxGuessAllowed;


        bool liarHidden;
        do {
            //::::::::::DO WHILE CHECK VARIABLES::::::::
            liarHidden = true;
            int userLiar = 0;
            int playerGuessLoopEnd = size; // used to end for loop



            //::::::::::CHECK FOR LIAR VARIABLES::::::::
            int liarLow = 0;
            int liarHigh = 1;

            //::::::::::PLAYER INFO VARIABLES::::::::
            string currentPlayer;// Current guessers name
            string challenger;
            string challengerFound;

            //********************TESTING AREA**********************
            if (testingInProgress) {
                loopLocation2++;
                cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
                cout << "::::::::::::::::::::::LOOP 2 TEST GUESSING::::::::::::::::" << endl;
                cout << "current guess loop is : " << loopLocation2 << endl;
                cout << "::::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
                cout << endl;
                cout << endl;
            }

            //----GUESSING ROUND LOOP GO UNTIL ALL PLAYERS GUESS OR LIAR CALLED
            for (int i = 0; i < playerGuessLoopEnd; i++) {
                currentPlayer = p[i].getName();

                //-------------Ask user to view there dice and options-----------
                bool displayDiceAndOptions;
                cout << currentPlayer << " - WOULD YOU LIKE TO SEE YOUR DICE AND GUESS OPTIONS? " << endl;
                cout << "0 for no 1 for yes " << endl;
                displayDiceAndOptions = checkValidInput(lowBool, highBool);
                if (displayDiceAndOptions) {
                    cout << "----------------------DICE OPTIONS-----------------------" << endl;

                    cout << "\nPlayer Options for kind of Dice and Number of that dice:" << endl;
                    cout << "\tDice\tAmount\n";
                    for (itr = allPlayerGuesses.begin(); itr != allPlayerGuesses.end(); ++itr) {
                        cout << '\t' << itr->first << '\t' << itr->second
                             << '\n';
                    }
                    cout << "----------------------PLAYER  DICE-----------------------" << endl;
                    //BUILD LOCAL VECTORS TO SORE AND ADD ROLLS
                    vector<int> userDice; // length of 5

                    //Get dice roll for each player in Player array
                    cout << p[i].getName() << " Your dice are: ";
                    userDice = p[i].getDice();
                    //int sizeDie;
                    //sizeDie = userDice.size();
                    //cout << " sizeDie: " << sizeDie << endl;
                    for (int i = 0; i < userDice.size(); i++) {
                        std::cout << userDice[i] << " ";
                    }
                    cout << endl;
                }

                //********************TESTING AREA**********************
                if (testingInProgress) {
                    cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
                    cout << "Iterate over all PLAYERS to get guesses  :" << endl;
                    cout << ":::::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
                    cout << endl;
                    cout << endl;
                }

                //  ::::::::Kind of dice input and validation:::::::
                //Kind of dice allowed
                int lowDice = 1;
                int highDice = 6;

                //  :::::::::::GET DICE TYPE GUESS AREA FROM  currentPlayer:::::::::::::::
                //Get User Input and validate it with function call checkValidInput Low high parameters
                cout << currentPlayer << ", What kind of dice is your guess? " << endl;
                userGuessedDie = checkValidInput(lowDice, highDice);
                //  Count of dice input
                cout << currentPlayer << ", And how many of dice type " << userGuessedDie << " ? " << endl;
                // gets the last guess allowed for that die
                mapCurrentValue = allPlayerGuesses.find(userGuessedDie)->second;

                // lowest guess must be one higher for that die AND max amount of dice in play
                mapMaxValue_totalDiceType = mapCurrentValue + 1;
                userGuessedNumOfDice = checkValidInput(mapMaxValue_totalDiceType, maxGuessAllowed);
                //********************TESTING AREA**********************
                if (testingInProgress) {
                    cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
                    cout << "::::::::::::::::::::::USER INPUT::::::::::::::::" << endl;
                    cout << "userGuessedNumOfDice: " << userGuessedNumOfDice << " userGuessedDie: " << userGuessedDie
                         << endl;
                }

                // sets the map to the current lowest guess allowed for last die kind and LOWER
                for (int i = 1; i <= userGuessedDie; ++i) {
                    allPlayerGuesses[i] = userGuessedNumOfDice + 1;
                }
                // sets the map to the current lowest guess allowed for last die kind and HIGHER
                for (int i = userGuessedDie + 1; i <= 6; ++i) {
                    allPlayerGuesses[i] = userGuessedNumOfDice;
                }

                //********************TESTING AREA**********************
                if (testingInProgress) {
                    cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
                    cout << "::::::::::::::::::::::MAP MANIPULATION AFTER GUESS::::::::::::::::" << endl;
                    cout << "\nuserGuessedNumOfDice.insert(" << userGuessedDie << " , " << userGuessedNumOfDice << ") :"
                         << endl;
                    cout << "\tKEY\tELEMENT\n";
                    for (itr = allPlayerGuesses.begin(); itr != allPlayerGuesses.end(); ++itr) {
                        cout << '\t' << itr->first << '\t' << itr->second
                             << '\n';
                    }
                }

                // CHECK FOR A LIAR FOR EACH PLAYER
                cout << "Does any one want to call a Liar? " << endl;
                cout << "If so type the integer 1 then hit enter IF NOT type zero" << endl;
                userLiar = checkValidInput(liarLow, liarHigh);

                // sets DoWhile loop boolean to false and shows table dice
                if (userLiar == 1) {
                    cout << " All stop a liar was called OR " << endl;
                    cout << " The table dice are:  ";
                    // Prints table dice
                    printDice(currentRoundDice);
                    cout << endl;
                    playerGuessLoopEnd = size; // ends for loop for iterating players by setting the size to max
                    i = playerGuessLoopEnd;
                    liarHidden = false;
                }
            }
            //end for loop of guesses

            //********************TESTING AREA**********************
            if (testingInProgress) {
                cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
                cout << "::::::::::::::::::::::LIAR CALLED BEGIN:::::::::::::::" << endl;
                for (int t = 0; t < size; t++) {
                    p[t].putData();
                }
                cout << ":::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
                cout << endl;
                cout << endl;
            }

            int currentChallengerWins;

//END FOR LOOP OF GUESSING
            //::::::::::::AREA TO CHECK IF CURRENT ROLLER IS A WINNER AND IF SO SET THERE WIN COUNT AND END ROUND
            if (userLiar == 1) { // only activated upon Liar called

                //::::  RESETS ALL THE SCORES TO ZERO EXCEPT FIRST PLAYER  ::::
                for(int kk = 0; kk < size; kk++){
                    p[kk].setScore(0);
                }

                cout << "Who was the challenger that called liar" << endl;
                cin >> challenger;

                //:::::FIND THE CHALLENGER:::::::::::::
                for (int ii = 0; ii < size; ii++) {
                    string tempName = p[ii].getName();
                    if (tempName == challenger) {
                        challengerFound = challenger;
                    }
                }
                cout << currentPlayer << " You have been challenged BY  " << challengerFound << endl;

                //:::::DETERMINE IF THE CURRENT PLAYER IS A WINNER OR THE CHALLENGER :::::::::::::
                // gets Game::game table dice
                auto &getTableDice = game.getTableDice();
                int counter = 0;

                for (auto x: getTableDice) {
                    counter += (x == userGuessedDie); // adds to counter each dice occurrence
                    // VECTOR SEARCH  userGuessedDie OF number OCCURRENCES
                    // TO WIN  userGuessedNumOfDice == VECTOR NUM OF OCCURRENCES
                }

                //set a win for the current guesser
                if (userGuessedNumOfDice == counter) {
                    cout << "userGuessedNumOfDice == counter) " << endl;
                    int currentPlayerWins;
                    //set a win for the current guesser
                    for (int iii = 0; iii < size; iii++) {
                        if (currentPlayer == p[iii].getName()) {
                            int tempWins;
                            tempWins = p[iii].getWins();
                            p[iii].setWins(1 + tempWins);
                            currentPlayerWins = p[iii].getWins();
                            p[0] = p[iii];  // put them in the first player to get a guess
                        }

                    }
                    cout << currentPlayer << " You have won! your score is " << currentPlayerWins << endl;
                    p[0].setScore(1);
                }

                //set a win for the current guesser
                if (userGuessedNumOfDice != counter) {
                    cout << "userGuessedNumOfDice != counter) " << endl;
                    int currentChallengerWins;
                    for (int iii = 0; iii < size; iii++) {
                        if (challengerFound == p[iii].getName()) {
                            int tempWins;
                            tempWins = p[iii].getWins();
                            p[iii].setWins(1 + tempWins);
                            currentChallengerWins = p[iii].getWins();
                            p[0] = p[iii]; // put them in the first player to get a guess
                        }

                    }
                    cout << challengerFound << " You have won! your WIN COUNT is: " << currentChallengerWins << endl;
                    p[0].setScore(1);
                }

                //:::::::::::::::::PRINT PLAYER DATA:::::::::::
                for (int t = 0; t < size; t++) {
                    p[t].putData();
                    cout << endl;
                }

                //Double check doWhile loop end
                if (userLiar == 1) {
                    liarHidden = false;
                }

            } //Guessing loop END
        }
        while (liarHidden);
        //********************TESTING AREA**********************
        if (testingInProgress) {
            cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::END OF WHILE GAMELOOP:::::::::::::::" << endl;
            cout << ":::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;

        }
        // :::::::::::::: DESTRUCTORS AREA::::::::::::::
        //CLEAR WHOLE MAP ELEMENTS
        allPlayerGuesses.clear();

        if (testingInProgress) {
            cout << "::::::::::::::::::::::CONSOLE OUTPUT::::::::::::::::" << endl;
            cout << "::::::::::::::::::::::CHECKING GAME TABLE DICE:::::::::::::::" << endl;
            cout << "::::::::::::::::END CONSOLE OUTPUT::::::::::::::::" << endl;
            cout << endl;
            cout << endl;
        }

        // Check to see for another round
        cout << "Play another round type-- 0 for NO, type-- 1 for YES"  << endl;
        playAgain = checkValidInput(lowBool, highBool);
        gameSize--;
        if ( gameSize == 0 || playAgain == 0){
            keepPlaying = false;
        }
        //Prints player data
        for (int t = 0; t < size; t++) {
            p[t].putData();
            cout << endl;
        }

    }
    while (keepPlaying);
    return 0;
}

void printDice(std::vector<int> &vector1) {
    int vecSize;
    vecSize = vector1.size();
    std::cout << std::endl;
    //std::cout << vecSize << " vector size " << std::endl;
    for (int i = 0; i < vector1.size(); i++){
        // std::cout << i;
        std::cout << vector1[i] << " " ;
    }
    std::cout << std::endl;
}

unsigned int checkValidInput(int param1, int param2) {
    bool validUserInput;
    unsigned int num;
    do {
        //check if user input is good, if not re-enter
        validUserInput = true;
        cout << "Please enter a positive value between " << param1 << " and " << param2 << " : " << endl;
        cin >> num;

        if ( cin.fail()) validUserInput = false;
        if ( num < param1 ) validUserInput = false;
        if ( num > param2 ) validUserInput = false;
        cin.clear(); // this insures no errors
        cin.ignore();
    }
    while (!validUserInput);

    return num;
}

void ReadFile() {
// Create a text string, which is used to output the text file
    string myText;
// Read from the text file
    ifstream MyReadFile("Liar.txt");
// Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        cout << myText << endl; // Output the text from the file
        }
// Close the file
    MyReadFile.close();
}
// roll the die for everyone
std::vector<int> rollDice() {
    int n = 5;
    std::vector<int> dice;
    int die;
    for (int i = 0; i < n; i++){
        die = (rand() % 6) + 1;
        dice.push_back(die);
    }
    return std::vector<int>(dice);
}

//:::::::::::::::::::REFERENCES USED HERE::::::::::::::
//--------MAP
//https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
// https://cplusplus.com/reference/map/map/begin/


//-------GENERAL
//https://www.w3schools.com/cpp/cpp_conditions_elseif.asp

//---------BOOKS
//C++17 Standard Library Quick Reference
//Peter Van Weert & Marc Gregoire
//https://books.apple.com/us/book/c-17-standard-library-quick-reference/id1477742306

//Learn C++ for Game Development
//Bruce Sutherland
//https://books.apple.com/us/book/learn-c-for-game-development/id899147468

//Advanced C++ Programming Cookbook
//Dr. Rian Quinn
//https://books.apple.com/us/book/advanced-c-programming-cookbook/id1497347384

//Array of objects in C++ with examples. (2021, November 17).
// GeeksforGeeks. https://www.geeksforgeeks.org/array-of-objects-in-c-with-examples/