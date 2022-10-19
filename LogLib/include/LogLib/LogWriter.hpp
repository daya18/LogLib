#pragma once

#include <vector>
#include <functional>
#include <fstream>

#include "Common.hpp"

namespace loglib
{
    class LogWriter
    {
    public:
        LogWriter ( std::string const & name );

        LogWriter & operator << ( LogEntry const & );
               
    private:
        std::vector <LogEntry> entries;
        std::ofstream fileStream;
    };
}