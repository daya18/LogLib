#include "Log.hpp"

loglib::Log & loglib::Log::operator << ( LogEntry const & entry )
{
    entries.push_back ( entry );
    return *this;
}