#pragma once

#include <GLFW/glfw3.h>

namespace loglib
{
    class LogWindow
    {
    public:
        LogWindow ();
        LogWindow ( LogWindow const & ) = delete;
        LogWindow ( LogWindow && ) = default;

        ~LogWindow ();

        LogWindow & operator = ( LogWindow const & ) = delete;
        LogWindow & operator = ( LogWindow && ) = default;
        
        void Update ();

    private:
        GLFWwindow * window;
    };
}