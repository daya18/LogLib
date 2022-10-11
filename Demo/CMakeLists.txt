cmake_minimum_required ( VERSION 3.24.2 )

project ( LogLibDemo )

add_executable ( LogLibDemo )

target_sources ( LogLibDemo PRIVATE source/Demo.cpp )

target_link_libraries ( LogLibDemo PRIVATE LogLib )