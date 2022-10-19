#pragma once

#include <vector>
#include <functional>
#include <fstream>

#include "Common.hpp"

namespace loglib
{
    class LogReader
    {
    public:
        LogReader ( std::string const & name );

        LogReader & operator >> ( LogEntry & );
        operator bool () const;

    private:
        LogEntry ParseLine ( std::string const & );

        std::ifstream fileStream;
        bool isDirty;
    };
}