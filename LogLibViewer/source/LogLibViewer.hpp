#pragma once

#include <vector>
#include <string>

#include "GLFWImGuiOGLWindow.hpp"
#include "ImGuiRenderer.hpp"

namespace loglib
{
    class LogLibViewer
    {
    public:
        LogLibViewer ( std::vector <std::string> const & args );

        void Run ();

    private:
        GLFWImGuiOGLWindow window;
        ImGuiRenderer renderer;
    };
}