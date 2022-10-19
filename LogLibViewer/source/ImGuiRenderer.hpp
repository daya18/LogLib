#pragma once

#include <unordered_map>

#include "ImGuiWindow.hpp"
#include "LogLib/LogLib.hpp"
#include <imgui.h>

namespace loglib
{
    class Log;
    
    class ImGuiRenderer
    {
    public:
        ImGuiRenderer ( ImGuiWindow & );
        ImGuiRenderer ( ImGuiWindow &, std::string const & logFilePath );

        void Render ();
        void SetFile ( std::string const & filePath );

    private:
        void SyncLog ();
        void HandleInput ();

        static std::unordered_map < LogSeverities, ImVec4> const severityColors;
        static std::unordered_map < LogSeverities, std::string> const severityTexts;
        static std::unordered_map < LogSeverities, ImGuiKey> const toggleSeverityKeys;
        
        std::unordered_map < LogSeverities, bool > showSeverityFlags;

        ImGuiWindow * window;
        loglib::LogReader logReader;

        std::vector <loglib::LogEntry> logEntries;
    };

}