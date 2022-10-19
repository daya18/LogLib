#pragma once

#include <string>

#include <GLFW/glfw3.h>
#include "imgui.h"

#include "ImGuiWindow.hpp"

namespace loglib
{
    class GLFWImGuiOGLWindow : public ImGuiWindow
    {
    public:
        GLFWImGuiOGLWindow ( std::string const & name );
        GLFWImGuiOGLWindow ( GLFWImGuiOGLWindow const & ) = delete;
        GLFWImGuiOGLWindow ( GLFWImGuiOGLWindow && ) = default;

        ~GLFWImGuiOGLWindow ();

        GLFWImGuiOGLWindow & operator = ( GLFWImGuiOGLWindow const & ) = delete;
        GLFWImGuiOGLWindow & operator = ( GLFWImGuiOGLWindow && ) = default;
        
        bool ShouldClose () const;

        void BeginFrame () override;
        void EndFrame () override;
        
    private:
        GLFWwindow * window;
        ImGuiContext * imguiContext;
    };
}