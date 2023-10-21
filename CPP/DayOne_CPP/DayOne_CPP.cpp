// DayOne_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

using std::cout;
using std::cin;
using namespace std::chrono;
using std::time_t;

int main()
{
    auto start = system_clock::now();

    std::string FILENAME = "D:\\Repos\\AdventOfCode\\2022\\AOC2022\\CS\\Shared\\Input\\DayOne.txt";

    std::ifstream infile(FILENAME);

    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
        {
            cout << line + "\n";
        }

        infile.close();
    }

    auto end = system_clock::now();

    duration<double> etSec = end - start;

    char timeBuf[21];

    std::ostringstream startOss;
    time_t startTime = system_clock::to_time_t(start);
    auto startT = time(&startTime);
    auto startMs = duration_cast<milliseconds>(start.time_since_epoch()) % 1000;
    std::tm brokenStart = *std::localtime(&startTime);
    startOss << std::put_time(&brokenStart, "%d/%m/%y %H:%M:%S");
    auto startStr = startOss.str();

    std::ostringstream endOss;
    time_t endTime = system_clock::to_time_t(end);
    auto endT = time(&endTime);
    auto endMs = duration_cast<milliseconds>(end.time_since_epoch()) % 1000;
    std::tm brokenEnd = *std::localtime(&endTime);
    endOss << std::put_time(&brokenEnd, "%d/%m/%y %H:%M:%S");
    auto endStr = endOss.str();

    cout << "Started at: " << startStr + "." << std::to_string(startMs.count()) << std::endl;
    cout << "Completed at: " << endStr << "." << std::to_string(endMs.count()) << std::endl;
    cout << "Elapsed time: " << etSec.count() << "s" << std::endl;

    cin.get();
}
