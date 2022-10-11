#pragma once

#include <GLFW/glfw3.h>
#include "imgui.h"

namespace loglib
{
    class Log;

    class LogWindow
    {
    public:
        LogWindow ( Log const & );
        LogWindow ( LogWindow const & ) = delete;
        LogWindow ( LogWindow && ) = default;

        ~LogWindow ();

        LogWindow & operator = ( LogWindow const & ) = delete;
        LogWindow & operator = ( LogWindow && ) = default;
        
        bool ShouldClose () const;
        void Update ();

    private:
        Log const * log;
        GLFWwindow * window;
        ImGuiContext * imguiContext;
    };
}