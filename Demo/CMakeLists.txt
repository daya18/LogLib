cmake_minimum_required ( VERSION 3.24.2 )

project ( LogLibDemo )

set ( CMAKE_CXX_STANDARD 17 )

add_executable ( LogLibDemo )

target_sources ( LogLibDemo PRIVATE source/Demo.cpp )

target_link_libraries ( LogLibDemo PRIVATE LogLib )