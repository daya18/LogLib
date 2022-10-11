#include "ImGui.hpp"

#include <imgui.h>

#include "Log.hpp"

namespace loglib { namespace 
{
    ImColor GetSeverityColor ( LogSeverities severity )
    {
        switch ( severity )
        {
            case LogSeverities::verbose: return ImColor ( 0, 255, 0, 255 );
            case LogSeverities::info: return ImColor ( 255, 255, 255, 255 );
            case LogSeverities::warning: return ImColor ( 255, 255, 0, 255 );
            case LogSeverities::error: return ImColor ( 255, 0, 0, 255 );
        }
    }
}}

void loglib::RenderImGui ( Log const & log, bool fullScreen )
{
    ImGuiWindowFlags windowFlags { 0 };
    
    if ( fullScreen ) 
    {
        windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize;
        
        ImGui::SetNextWindowPos ( { 0, 0 } );
        ImGui::SetNextWindowSize ( ImGui::GetIO().DisplaySize );
    }

    ImGui::Begin ( "LogWindow", nullptr, windowFlags );
    
    for ( auto const & entry : log.GetEntries () )
    {
        ImGui::TextColored ( GetSeverityColor ( entry.severity ), "%s", entry.data.data () );
    }

    ImGui::End ();
}