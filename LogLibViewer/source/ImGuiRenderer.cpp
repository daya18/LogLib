#include "ImGuiRenderer.hpp"

#include <iostream>

std::unordered_map <loglib::LogSeverities, ImVec4> const 
loglib::ImGuiRenderer::severityColors
{
    { LogSeverities::verbose,   { 0.0f, 1.0f, 0.0f, 1.0f } },
    { LogSeverities::info,      { 1.0f, 1.0f, 1.0f, 1.0f } },
    { LogSeverities::warning,   { 1.0f, 1.0f, 0.0f, 1.0f } },
    { LogSeverities::error,     { 1.0f, 0.0f, 0.0f, 1.0f } }
};

std::unordered_map < loglib::LogSeverities, std::string> const 
loglib::ImGuiRenderer::severityTexts
{
    { LogSeverities::verbose,   "Verbose" },
    { LogSeverities::info,      "Info" },
    { LogSeverities::warning,   "Warning" },
    { LogSeverities::error,     "Error" },
};

std::unordered_map < loglib::LogSeverities, ImGuiKey> const
loglib::ImGuiRenderer::toggleSeverityKeys
{
    { LogSeverities::verbose,   ImGuiKey_V},
    { LogSeverities::info,      ImGuiKey_I },
    { LogSeverities::warning,   ImGuiKey_W },
    { LogSeverities::error,     ImGuiKey_E },
};

loglib::ImGuiRenderer::ImGuiRenderer ( ImGuiWindow & window, std::string const & logFilePath )
:   
    window      ( & window ),
    logReader   ( logFilePath ),
    
    showSeverityFlags {
        { LogSeverities::verbose, true },
        { LogSeverities::info, true },
        { LogSeverities::warning, true },
        { LogSeverities::error, true },
    }
{
}

void loglib::ImGuiRenderer::Render ()
{
    SyncLog ();
    HandleInput ();
    
    ImGuiWindowFlags windowFlags { ImGuiWindowFlags_NoBackground };
    
    windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize;
    
    ImGui::SetNextWindowPos ( { 0, 0 } );
    ImGui::SetNextWindowSize ( ImGui::GetIO().DisplaySize );

    ImGui::Begin ( "LogWindow", nullptr, windowFlags );

        ImGui::PushStyleColor ( ImGuiCol_ChildBg, { 0.2f, 0.2f, 0.2f, 1.0f } ); 

        ImGui::BeginChild ( "Buttons", { ImGui::GetWindowWidth (), 22.0f } );

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

            for ( auto const & entry : logEntries )
            {
                if ( showSeverityFlags.at ( entry.severity ) )
                    ImGui::TextColored ( severityColors.at ( entry.severity ), "%s", entry.data.data () );
            }

        ImGui::EndChild ();
        
    ImGui::End ();
}

void loglib::ImGuiRenderer::HandleInput ()
{
    auto io { ImGui::GetIO () };
}

void loglib::ImGuiRenderer::SyncLog ()
{
    LogEntry entry;

    while ( logReader >> entry )
        logEntries.push_back ( entry );
}