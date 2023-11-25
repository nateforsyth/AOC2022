#include "pch.h"
#include "UtilityLibrary.h"

#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>

using std::time_t;
using namespace std::chrono;

std::string ConvertTimePointToNzString(std::chrono::system_clock::time_point timePoint)
{
    std::ostringstream startOss;
    time_t startTime = std::chrono::system_clock::to_time_t(timePoint);
    std::tm brokenStart = *std::localtime(&startTime);
    startOss << std::put_time(&brokenStart, "%d/%m/%y %H:%M:%S");
    auto startStr = startOss.str();

    return startStr;
}

std::chrono::milliseconds ConvertTimePointToMs(std::chrono::system_clock::time_point timePoint)
{
    auto ms = duration_cast<milliseconds>(timePoint.time_since_epoch()) % 1000;
    return ms;
}
