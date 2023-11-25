// UtilityLibrary.h - Contains declarations of utility functions
#pragma once

#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>

#ifdef UTILITYLIBRARY_EXPORTS
#define UTILITYLIBRARY_API __declspec(dllexport)
#else
#define UTILITYLIBRARY_API __declspec(dllimport)
#endif

/// <summary>
/// Convert a given timepoint into a DateTime string in NZ format
/// </summary>
/// <param name="timePoint">Timepoint instance</param>
/// <returns>NZ formatted DateTime string value</returns>
UTILITYLIBRARY_API std::string ConvertTimePointToNzString(std::chrono::system_clock::time_point timePoint);

/// <summary>
/// Convert a given timepoint into milliseconds since epoch
/// </summary>
/// <param name="timePoint">Timepoint instance</param>
/// <returns>Milliseconds since epoch</returns>
UTILITYLIBRARY_API std::chrono::milliseconds ConvertTimePointToMs(std::chrono::system_clock::time_point timePoint);
