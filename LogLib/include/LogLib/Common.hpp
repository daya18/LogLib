#pragma once

#include <string>
#include <unordered_map>

namespace loglib
{
    enum LogSeverities { verbose, info, warning, error };
    
    struct LogEntry
    {
        LogSeverities severity;
        std::string data;
    };

    extern std::unordered_map <LogSeverities, std::string> const logEntrySeverityPrefixes;
}