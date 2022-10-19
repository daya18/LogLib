#include "LogLibViewer.hpp"

loglib::LogLibViewer::LogLibViewer ( std::vector <std::string> const & args )
: 
    window ( "LogLib Viewer" ),
    renderer ( window )
{
    if ( args.size () > 0 )
        renderer.SetFile ( args [ 1 ] );
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
