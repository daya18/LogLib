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
        void SetFileDropCallback ( FileDropCallback ) override;

    private:
        static GLFWImGuiOGLWindow & GetThis ( GLFWwindow * );
        static void glfwDropCallback ( GLFWwindow *, int, char const** );

        GLFWwindow * window;
        ImGuiContext * imguiContext;

        FileDropCallback fileDropCallback;
    };

    // IMPLEMENTATION
    inline void GLFWImGuiOGLWindow::SetFileDropCallback ( FileDropCallback callback )
    { fileDropCallback = callback; }

    inline GLFWImGuiOGLWindow & GLFWImGuiOGLWindow::GetThis ( GLFWwindow * window ) 
    { return * static_cast < GLFWImGuiOGLWindow *> ( glfwGetWindowUserPointer ( window ) ); }
}