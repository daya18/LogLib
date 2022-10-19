cmake_minimum_required ( VERSION 3.24.2 )

project ( LogLib )

set ( CMAKE_CXX_STANDARD 17 )

add_library ( LogLib )

target_include_directories ( LogLib 
    INTERFACE
        include
    
    PRIVATE 
        include/LogLib 
        source
)

target_sources ( LogLib
    PRIVATE
        source/Common.cpp
        source/LogWriter.cpp
        source/LogReader.cpp
)