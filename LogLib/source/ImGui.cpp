#include "ImGui.hpp"

#include <unordered_map>
#include <iostream>

#include <imgui.h>

#include "Log.hpp"

namespace loglib { namespace 
{
    std::unordered_map <LogSeverities, ImVec4> const severityColors
    {
        { LogSeverities::verbose,   { 0.0f, 1.0f, 0.0f, 1.0f } },
        { LogSeverities::info,      { 1.0f, 1.0f, 1.0f, 1.0f } },
        { LogSeverities::warning,   { 1.0f, 1.0f, 0.0f, 1.0f } },
        { LogSeverities::error,     { 1.0f, 0.0f, 0.0f, 1.0f } }
    };

    std::unordered_map < LogSeverities, std::string> const severityTexts
    {
        { LogSeverities::verbose,   "Verbose" },
        { LogSeverities::info,      "Info" },
        { LogSeverities::warning,   "Warning" },
        { LogSeverities::error,     "Error" },
    };
}}

void loglib::RenderImGui ( Log const & log, bool fullScreen )
{
    ImGuiWindowFlags windowFlags { ImGuiWindowFlags_NoBackground };
    
    if ( fullScreen ) 
    {
        windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize;
        
        ImGui::SetNextWindowPos ( { 0, 0 } );
        ImGui::SetNextWindowSize ( ImGui::GetIO().DisplaySize );
    }

    ImGui::Begin ( "LogWindow", nullptr, windowFlags );

        ImGui::PushStyleColor ( ImGuiCol_ChildBg, { 0.2f, 0.2f, 0.2f, 1.0f } ); 

        ImGui::BeginChild ( "Buttons", { ImGui::GetWindowWidth (), 22.0f } );

            //ImGui::Spacing ();
            static std::unordered_map < LogSeverities, bool > showSeverityFlags
            {
                { LogSeverities::verbose, true },
                { LogSeverities::info, true },
                { LogSeverities::warning, true },
                { LogSeverities::error, true },
            };

            for ( auto const & [ severity, text ] : severityTexts )
            {
                ImGui::SameLine ();
                ImGui::PushStyleColor ( ImGuiCol_CheckMark, severityColors.at ( severity ) );
                ImGui::PushStyleColor ( ImGuiCol_Text, severityColors.at ( severity ) );
                ImGui::Checkbox ( text.data (), & showSeverityFlags [ severity ] );
                ImGui::PopStyleColor ( 2 );
            }

        ImGui::EndChild ();
        ImGui::PopStyleColor ();

        ImGui::Spacing ();
        ImGui::BeginChild ( "Log Entries" );

            for ( auto const & entry : log.GetEntries () )
            {
                if ( showSeverityFlags.at ( entry.severity ) )
                    ImGui::TextColored ( severityColors.at ( entry.severity ), "%s", entry.data.data () );
            }

        ImGui::EndChild ();
        
    ImGui::End ();
}