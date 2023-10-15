// DayOne_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;

int main()
{
    std::string FILENAME = "D:\\Repos\\AdventOfCode\\2022\\AOC2022\\Shared\\Input\\DayOne.txt";

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

    

    //cout << "What is your name?\n";

    //std::string str;
    //std::getline(cin, str); // equivalent to C# Console.WriteLine("string")

    //cout << "\nHello " + str + "!\n\nPress any key to exit...\n";

    cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
