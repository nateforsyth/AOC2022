// DayOne_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

#include "UtilityLibrary.h"

using std::cout;
using std::cin;
using namespace std::chrono;
using std::time_t;

int main()
{
    auto start = system_clock::now();

    std::string FILENAME = "..\\..\\CS\\Shared\\Input\\DayOne.txt";

    std::ifstream infile(FILENAME);

    if (infile.is_open() && infile.good())
    {
        std::string line;
        std::stringstream strStream;

        while (std::getline(infile, line))
        {
            strStream << line << std::endl;

            cout << line + "\n";
        }

        infile.close();
    }
    else {
        cout << "Could not open file: " + FILENAME + "\n\n";
    }

    auto end = system_clock::now();

    duration<double> etSec = end - start;

    //char timeBuf[21];

    std::string startStr = ConvertTimePointToNzString(start);
    std::chrono::milliseconds startMs = ConvertTimePointToMs(start);

    std::string endStr = ConvertTimePointToNzString(end);
    std::chrono::milliseconds endMs = ConvertTimePointToMs(end);

    cout << "Started at: " << startStr + "." << std::to_string(startMs.count()) << std::endl;
    cout << "Completed at: " << endStr << "." << std::to_string(endMs.count()) << std::endl;
    cout << "Elapsed time: " << etSec.count() << "s" << std::endl;

    cin.get();
}
