#include "Common.hpp"

std::unordered_map <loglib::LogSeverities, std::string> const 
loglib::logEntrySeverityPrefixes
{
    { loglib::LogSeverities::verbose,   "[VERBOSE]" },
    { loglib::LogSeverities::info,      "[INFO]   " },
    { loglib::LogSeverities::warning,   "[WARNING]" },
    { loglib::LogSeverities::error,     "[ERROR]  " },
};