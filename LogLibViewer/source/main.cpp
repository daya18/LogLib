#include <string>

#include "LogLibViewer.hpp"

int main ( int argc, char * argv [] )
{
    loglib::LogLibViewer viewer { { argv, argv + argc } };
    viewer.Run ();
}