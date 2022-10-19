#include "LogLib/LogLib.hpp"

#include <cstdlib>
#include <random>
#include <array>
#include <filesystem>
#include <thread>

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

    loglib::Logger logger { "Demo" };

    logger << loglib::LogEntry { loglib::LogSeverities::verbose, 
        "Working directory:" + std::filesystem::current_path ().string () };
    
    while ( 1 )
    {
        if ( generateLogDistribution ( randomEngine ) == 0 )
        {
            auto severity = logSeverities [ logSeverityDistribution ( randomEngine ) ];
            
            using namespace std::string_literals;

            std::string data = "Log "s //+ std::to_string ( logger.GetEntries().size () )
                + ": "s + GetLogData ( severity );

            logger << loglib::LogEntry { severity, data };

            std::this_thread::sleep_for ( std::chrono::seconds ( 2 ) );
        }       
    }
}