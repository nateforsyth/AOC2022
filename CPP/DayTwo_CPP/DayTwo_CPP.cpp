// DayTwo_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

#include "UtilityLibrary.h"

using std::cout;
using std::cin;
using namespace std::chrono;

int getRoundScore(char opponentChoice, char playerChoiceOrDesiredResult, bool partTwo);

enum class OpponentChoice {
    Rock = 'A', // Score: 1
    Paper = 'B', // Score: 2
    Scissors = 'C' // Score: 3
};

enum PlayerChoice {
    Rock = 'X', // Score: 1
    Paper = 'Y', // Score: 2
    Scissors = 'Z' // Score: 3
};

enum class Result {
    Invalid = -1,
    Win = 6,
    Draw = 3,
    Loss = 0
};

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

    int playerScore1 = 0;
    int playerScore2 = 0;

    if (infile.is_open() && infile.good())
    {
        std::string line;

        while (std::getline(infile, line))
        {
            char* line_char_arr = new char[line.length() + 1];
            strcpy(line_char_arr, line.c_str());

            char playerChoice = line_char_arr[0];
            char playerChoiceOrDesiredResult = *(line_char_arr + 2);

            playerScore1 = playerScore1 + getRoundScore(playerChoice, playerChoiceOrDesiredResult, false);
            playerScore2 = playerScore2 + getRoundScore(playerChoice, playerChoiceOrDesiredResult, true);
        }        
    }

    infile.close();

    cout << "Part one: " << playerScore1 << std::endl;
    cout << "Part two: " << playerScore2 << std::endl;

    // end program and calculate elapsed duration
    std::chrono::system_clock::time_point end = system_clock::now();

    std::string startStr = convert_timepoint_to_nz_time(start);
    std::chrono::milliseconds startMs = convert_timepoint_to_ms(start);

    std::string endStr = convert_timepoint_to_nz_time(end);
    std::chrono::milliseconds endMs = convert_timepoint_to_ms(end);

    cout << "Started at: " << startStr + "." << std::to_string(startMs.count()) << std::endl;
    cout << "Completed at: " << endStr << "." << std::to_string(endMs.count()) << std::endl;
    cout << "Elapsed time: " << (endMs.count() - startMs.count()) << "ms" << std::endl;

    std::cin.get();
}

OpponentChoice convertOpponentChoiceChar(char opponentString)
{
    return static_cast<OpponentChoice>(opponentString);
}

PlayerChoice convertPlayerChoiceChar(char playerString)
{
    return static_cast<PlayerChoice>(playerString);
}

Result getResultForPlayerChoice(OpponentChoice opponentChoice, PlayerChoice playerChoice)
{
    Result r{};

    switch (opponentChoice)
    {
    case OpponentChoice::Rock:
        r = playerChoice == PlayerChoice::Paper ? Result::Win : (playerChoice == PlayerChoice::Rock ? Result::Draw : Result::Loss);
        break;
    case OpponentChoice::Paper:
        r = playerChoice == PlayerChoice::Scissors ? Result::Win : (playerChoice == PlayerChoice::Paper ? Result::Draw : Result::Loss);
        break;
    case OpponentChoice::Scissors:
        r = playerChoice == PlayerChoice::Rock ? Result::Win : (playerChoice == PlayerChoice::Scissors ? Result::Draw : Result::Loss);
        break;
    default:
        r = Result::Invalid;
        break;
    }

    return r;
}

PlayerChoice getPlayerChoice(OpponentChoice opponentChoice, Result desiredResult)
{
    PlayerChoice playerChoice{};

    switch (opponentChoice)
    {
    case OpponentChoice::Rock:
        playerChoice = desiredResult == Result::Win ? PlayerChoice::Paper : (desiredResult == Result::Draw ? PlayerChoice::Rock : PlayerChoice::Scissors);
        break;
    case OpponentChoice::Paper:
        playerChoice = desiredResult == Result::Win ? PlayerChoice::Scissors : (desiredResult == Result::Draw ? PlayerChoice::Paper : PlayerChoice::Rock);
        break;
    case OpponentChoice::Scissors:
        playerChoice = desiredResult == Result::Win ? PlayerChoice::Rock : (desiredResult == Result::Draw ? PlayerChoice::Scissors : PlayerChoice::Paper);
        break;
    default:
        break;
    }

    return playerChoice;
}

int getRoundScore(char opponentChoiceChar, char playerChoiceOrDesiredResultChar, bool partTwo)
{
    OpponentChoice opponentChoice = convertOpponentChoiceChar(opponentChoiceChar);
    PlayerChoice playerChoice{};
    Result result{};

    if (!partTwo) // part one
    {
        playerChoice = convertPlayerChoiceChar(playerChoiceOrDesiredResultChar);
        result = result = getResultForPlayerChoice(opponentChoice, playerChoice);
    }
    else // part two
    {
        result = playerChoiceOrDesiredResultChar == 'X' ? Result::Loss : (playerChoiceOrDesiredResultChar == 'Y' ? Result::Draw : Result::Win);
        playerChoice = getPlayerChoice(opponentChoice, result);
    }

    int resultValue = static_cast<int>(result);

    if (playerChoice == PlayerChoice::Rock)
    {
        return resultValue + 1;
    }
    else if (playerChoice == PlayerChoice::Paper)
    {
        return resultValue + 2;
    }
    else {
        return resultValue + 3;
    }
}
