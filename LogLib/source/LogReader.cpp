#include "LogReader.hpp"
#include <iostream>
#include <filesystem>

loglib::LogReader::LogReader ( std::string const & filePath )
: 
    fileStream ( filePath, std::ios::in )//,
    //isDirty ( ! fileStream.eof () )
{
    if ( ! std::filesystem::exists ( filePath ) )
        std::cout << "File " << filePath << " not found" << std::endl;
}

loglib::LogReader & loglib::LogReader::operator >> ( LogEntry & entry )
{
    fileStream.clear ();
    fileStream.sync ();
        
    if ( fileStream.eof () ) return *this;

    std::string line;
    std::getline ( fileStream, line );
    
    if ( line.empty () ) return *this;

    entry = ParseLine ( line );
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

loglib::LogReader::operator bool () const { return ! fileStream.eof (); }