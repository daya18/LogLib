#pragma once

#include <string>
#include <vector>

namespace loglib
{
    enum LogSeverities { verbose, info, warning, error };
    
    struct LogEntry
    {
        LogSeverities severity;
        std::string data;
    };

    class Log
    {
    public:
        Log & operator << ( LogEntry const & );
        
        std::vector <LogEntry> const & GetEntries () const;

    private:
        std::vector <LogEntry> entries;
    };


    // IMPLEMENTATION
    inline std::vector <LogEntry> const & Log::GetEntries () const { return entries; }
}