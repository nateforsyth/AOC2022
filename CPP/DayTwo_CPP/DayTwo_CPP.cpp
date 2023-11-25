// DayTwo_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using std::cout;
using std::cin;
using namespace std::chrono;

int get_player_score(std::string opponent, std::string player);

int main()
{
    /*
        Who         Sel Shape       Score
        -----------|---|-----------|-----
        Opponent    A   Rock        1
        Opponent    B   Paper       2
        Opponent    C   Scissors    3

        Player      X   Rock        1
        Player      Y   Paper       2
        Player      Z   Scissors    3
    
        Result  Score
        -------|-----
        Win     6
        Draw    3
        Loss    0

        Round score = selected shape + round outcome
        Total score = sum of all rounds        
    */

    std::chrono::system_clock::time_point start = system_clock::now();
    std::string FILENAME = "..\\..\\CS\\Shared\\Input\\DayTwo.txt";
    std::ifstream infile(FILENAME);

    int playerScore = 0;

    if (infile.is_open() && infile.good())
    {
        std::string line;

        while (std::getline(infile, line))
        {
            std::string o = line.substr(0, 1);
            std::string p = line.substr(2, 1);
            cout << line << "\n";

            playerScore = playerScore + get_player_score(o, p);
        }        
    }

    infile.close();

    cout << "\n" << playerScore << "\n";

    std::cin.get();
}

int get_player_score(std::string opponent, std::string player)
{
    if (opponent == "A") // rock
    {
        if (player == "X") // rock (1), draw (3)
        {
            return 1 + 3;
        }
        else if (player == "Y") // paper (2), win (6)
        {
            return 2 + 6;
        }
        else { // player must be Z, scissors (3), loss (0)
            return 3 + 0;
        }
    }
    else if (opponent == "B") // paper
    {
        if (player == "X") // rock (1), loss (0)
        {
            return 1 + 0;
        }
        else if (player == "Y") // paper (2), draw (3)
        {
            return 2 + 3;
        }
        else { // player must be Z, scissors (3), win (6)
            return 3 + 6;
        }
    }
    else { // opponent must be C, scissors
        if (player == "X") // rock (1), win (6)
        {
            return 1 + 6;
        }
        else if (player == "Y") // paper (2), loss (0)
        {
            return 2 + 0;
        }
        else { // player must be Z, scissors (3), draw (3)
            return 3 + 3;
        }
    }
}
