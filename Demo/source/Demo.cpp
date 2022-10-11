#include "LogLib/Log.hpp"
#include "LogLib/LogWindow.hpp"

#include <cstdlib>
#include <random>
#include <array>

std::string GetLogData ( loglib::LogSeverities severity )
{
    switch ( severity )
    {
        case loglib::LogSeverities::verbose:    return "I am a verbose";
        case loglib::LogSeverities::info:       return "I am an info";
        case loglib::LogSeverities::warning:    return "I am a warning";
        case loglib::LogSeverities::error:      return "I am an error";
    }
}

int main ()
{
    static constexpr std::array <loglib::LogSeverities, 4> logSeverities { 
        loglib::LogSeverities::verbose,
        loglib::LogSeverities::info,
        loglib::LogSeverities::warning,
        loglib::LogSeverities::error 
    };

    std::default_random_engine randomEngine;
    std::uniform_int_distribution <int> generateLogDistribution ( 0, 30 );
    std::uniform_int_distribution <int> logSeverityDistribution ( 0, 3 );

    loglib::Log log;
    loglib::LogWindow logWindow { log };

    while ( ! logWindow.ShouldClose () )
    {
        if ( generateLogDistribution ( randomEngine ) == 0 )
        {
            auto severity = logSeverities [ logSeverityDistribution ( randomEngine ) ];
            
            using namespace std::string_literals;

            std::string data = "Log "s + std::to_string ( log.GetEntries().size () )
                + ": "s + GetLogData ( severity );

            log << loglib::LogEntry { severity, data };
        }
        
        logWindow.Update ();
    }
}