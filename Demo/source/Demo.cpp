#include "LogLib/LogWindow.hpp"

int main ()
{
    loglib::LogWindow logWindow;

    while ( 1 )
        logWindow.Update ();
}