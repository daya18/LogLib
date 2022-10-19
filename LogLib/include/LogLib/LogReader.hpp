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
        LogReader ();
        LogReader ( std::string const & );
        
        LogReader & operator >> ( LogEntry & );
        operator bool () const;

        bool SetFile ( std::string const & filePath );
        std::string const & GetFile () const;

    private:
        LogEntry ParseLine ( std::string const & );

        std::string filePath;
        std::ifstream fileStream;
        bool isDirty;
    };

    // IMPLEMENTATION
    inline LogReader::LogReader () {}
    inline LogReader::LogReader ( std::string const & filePath ) { SetFile ( filePath ); }
    inline std::string const & LogReader::GetFile () const { return filePath; } 
}