#include "LogWriter.hpp"

loglib::LogWriter::LogWriter ( std::string const & filePath )
: fileStream ( filePath + ".llog", std::ios::out | std::ios::trunc )
{
}

loglib::LogWriter & loglib::LogWriter::operator << ( LogEntry const & entry )
{
    entries.push_back ( entry );

    fileStream << logEntrySeverityPrefixes.at ( entry.severity ) << ' ' << entry.data << std::endl;
    fileStream.flush ();

    return *this;
}