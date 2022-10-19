#include "LogLibViewer.hpp"

loglib::LogLibViewer::LogLibViewer ( std::vector <std::string> const & args )
: 
    window ( "LogLibViewer" ),
    renderer ( window, args.size () > 0 ? args [ 1 ] : "" )
{
}

void loglib::LogLibViewer::Run ()
{
    while ( ! window.ShouldClose () )
    {
        window.BeginFrame ();
        renderer.Render ();
        window.EndFrame ();
    }
}
