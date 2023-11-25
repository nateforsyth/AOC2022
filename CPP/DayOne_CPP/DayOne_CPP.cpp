// DayOne_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <map>
#include <algorithm>

#include "UtilityLibrary.h"

using std::cout;
using std::cin;
using namespace std::chrono;

template<typename TKey, typename TValue>
std::pair<TKey, TValue> get_element_with_max_int_value(const std::map<TKey, TValue>& x);
template<typename TKey, typename TValue>
std::pair<TValue, TKey> invert_pair(const std::pair<TKey, TValue>& pair);
template<typename TKey, typename TValue>
std::multimap<TValue, TKey> sort_map_by_value(const std::map<TKey, TValue>& source);

int main()
{
    std::chrono::system_clock::time_point start = system_clock::now();
    std::string FILENAME = "..\\..\\CS\\Shared\\Input\\DayOne.txt";
    std::ifstream infile(FILENAME);
    std::map<int, int> elves = {};

    if (infile.is_open() && infile.good())
    {
        std::string line;
        std::stringstream strStream;

        int currentElf = 0;
        int currentElfCarrying = 0;

        while (std::getline(infile, line))
        {
            if (line == "") // initialise next Elf
            {
                elves.insert(std::make_pair(currentElf++, currentElfCarrying));
                currentElfCarrying = 0;
            }
            else // current Elf, add to load
            {
                const size_t length = line.length();
                char* lineArray = new char[length + 1];
                strcpy(lineArray, line.c_str());

                int i = parse_int(lineArray);

                if (i != -1)
                {
                    currentElfCarrying += i;
                }

                strStream << i << std::endl;
                cout << line + "\n";

                delete[] lineArray;
            }
        }

        infile.close();
    }
    else {
        cout << "Could not open file: " + FILENAME + "\n\n";
    }

    // retrieve elves carrying the top 3 heaviest loads
    std::pair<int, int> elf1 = get_element_with_max_int_value(elves);
    
    elves.erase(elf1.first);
    std::pair<int, int> elf2 = get_element_with_max_int_value(elves);
    
    elves.erase(elf2.first);
    std::pair<int, int> elf3 = get_element_with_max_int_value(elves);
    
    elves.clear();

    // aggregate top 3 loads
    int total = elf1.second + elf2.second + elf3.second;

    cout << "\nThe strongest 3 elves are carrying a total of " + std::to_string(total) + " calories\n";
    cout << "\tAlpha is carrying:\t" + std::to_string(elf1.second) + "\n";
    cout << "\tBeta is carrying:\t" + std::to_string(elf2.second) + "\n";
    cout << "\tGamma is carrying:\t" + std::to_string(elf3.second) + "\n\n";

    // end program and calculate elapsed duration
    std::chrono::system_clock::time_point end = system_clock::now();

    std::string startStr = convert_timepoint_to_nz_time(start);
    std::chrono::milliseconds startMs = convert_timepoint_to_ms(start);

    std::string endStr = convert_timepoint_to_nz_time(end);
    std::chrono::milliseconds endMs = convert_timepoint_to_ms(end);

    cout << "Started at: " << startStr + "." << std::to_string(startMs.count()) << std::endl;
    cout << "Completed at: " << endStr << "." << std::to_string(endMs.count()) << std::endl;
    cout << "Elapsed time: " << (endMs.count() - startMs.count()) << "ms" << std::endl;

    cin.get();
}

/// <summary>
/// Get the element that has the maximum value in a map of Type Keys and Type Values
/// </summary>
/// <typeparam name="TKey">Type Key</typeparam>
/// <typeparam name="TValue">Type Value</typeparam>
/// <param name="map"></param>
/// <returns>Element in map that has highest int value</returns>
template<typename TKey, typename TValue>
std::pair<TKey, TValue> get_element_with_max_int_value(const std::map<TKey, TValue> & map) // TODO find out why this can't be in the DLL .h file
{
    using pairtype = std::pair<TKey, TValue>;
    return *std::max_element(map.begin(), map.end(), [](const pairtype& p1, const pairtype& p2)
    {
        return p1.second < p2.second;
    });
}

/// <summary>
/// Invert a pair
/// </summary>
/// <typeparam name="TKey">Type Key</typeparam>
/// <typeparam name="TValue">Type Value</typeparam>
/// <param name="x"></param>
/// <returns>Inverted pair</returns>
template<typename TKey, typename TValue>
std::pair<TValue, TKey> invert_pair(const std::pair<TKey, TValue>& pair)
{
    return std::pair<TValue, TKey>(pair.second, pair.first);
}

/// <summary>
/// Sort a map by Value
/// </summary>
/// <typeparam name="TKey">Type Key</typeparam>
/// <typeparam name="TValue">Type Value</typeparam>
/// <param name="source"></param>
/// <returns>Map sorted by Value</returns>
template<typename TKey, typename TValue>
std::multimap<TValue, TKey> sort_map_by_value(const std::map<TKey, TValue>& source)
{
    std::multimap<TValue, TKey> sortedSource;
    std::transform(source.begin(), source.end(), std::inserter(sortedSource, sortedSource.begin()), invert_pair<TKey, TValue>);

    return sortedSource;
}
