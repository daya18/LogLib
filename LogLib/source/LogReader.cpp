#include "LogReader.hpp"
#include <iostream>
#include <filesystem>

loglib::LogReader & loglib::LogReader::operator >> ( LogEntry & entry )
{
    fileStream.clear ();
    fileStream.sync ();
        
    if ( fileStream.good () )
    {
        std::string line;
        std::getline ( fileStream, line );
        
        if ( line.empty () ) return *this;
        
        entry = ParseLine ( line );
    }
    
    return *this;
}

loglib::LogEntry loglib::LogReader::ParseLine ( std::string const & line )
{
    LogSeverities severity { 
            line.find ( "[VERBOSE]" )   != line.npos ? LogSeverities::verbose 
        :   line.find ( "[INFO]" )      != line.npos ? LogSeverities::info
        :   line.find ( "[WARNING]" )   != line.npos ? LogSeverities::warning
        :   LogSeverities::error 
    };

    std::string data { line.substr ( line.find_first_of ( '[' ) + 10 ) };
    
    return { severity, data };
}

loglib::LogReader::operator bool () const { return fileStream.good (); }

bool loglib::LogReader::SetFile ( std::string const & filePath )
{

    if ( ! std::filesystem::exists ( filePath ) )
    {
        std::cout << "Log file " << filePath << " not found" << std::endl;
        return false;
    }

    fileStream.close ();
    fileStream.clear ();
    fileStream.open ( filePath, std::ios::in );
    
    this->filePath = filePath;

    std::cout << "Opened file " << filePath << std::endl;

    return true;
}
