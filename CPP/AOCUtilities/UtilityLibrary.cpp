#include "pch.h"
#include "UtilityLibrary.h"

#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>

using std::time_t;
using namespace std::chrono;

std::string convert_timepoint_to_nz_time(std::chrono::system_clock::time_point timePoint)
{
    std::ostringstream startOss;
    time_t startTime = std::chrono::system_clock::to_time_t(timePoint);
    std::tm brokenStart = *std::localtime(&startTime);
    startOss << std::put_time(&brokenStart, "%d/%m/%y %H:%M:%S");
    auto startStr = startOss.str();

    return startStr;
}

std::chrono::milliseconds convert_timepoint_to_ms(std::chrono::system_clock::time_point timePoint)
{
    auto ms = duration_cast<milliseconds>(timePoint.time_since_epoch()) % 1000;
    return ms;
}

int parse_int(char const* s)
{
    try
    {
        if (s == NULL || *s == '\0')
        {
            throw std::invalid_argument("Null or empty string argument");
        }

        bool negate = (s[0] == '-');
        if (*s == '+' || *s == '-')
        {
            ++s;
        }

        if (*s == '\0')
        {
            throw std::invalid_argument("Sign character only");
        }

        int result = 0;
        while (*s)
        {
            if (*s < '0' || *s > '9')
            {
                throw std::invalid_argument("Invalid input string");
            }

            result = result * 10 - (*s - '0'); // handle result as if it's negative
            ++s;
        }

        return negate ? result : -result; // if we're negating, invert to positive
    }
    catch (const std::exception&)
    {
        //std::cerr << e.what() << std::endl;
        return -1;
    }
}
