#include "GLFWImGuiOGLWindow.hpp"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

loglib::GLFWImGuiOGLWindow::GLFWImGuiOGLWindow ( std::string const & name )
{
    glfwInit ();

    window = glfwCreateWindow ( 500, 500, name.data (), nullptr, nullptr );
    glfwSetWindowUserPointer ( window, this );

    glfwMakeContextCurrent ( window );

    imguiContext = ImGui::CreateContext ();
    
    ImGui_ImplGlfw_InitForOpenGL ( window, true );
    ImGui_ImplOpenGL3_Init ();
    
    ImGui::StyleColorsDark ();
    
    glfwSetDropCallback ( window, glfwDropCallback );
}

loglib::GLFWImGuiOGLWindow::~GLFWImGuiOGLWindow ()
{
    glfwDestroyWindow ( window );
    glfwTerminate ();
}

bool loglib::GLFWImGuiOGLWindow::ShouldClose () const
{
    return glfwWindowShouldClose ( window );
}

void loglib::GLFWImGuiOGLWindow::BeginFrame ()
{
    glfwPollEvents ();

    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    ImGui_ImplOpenGL3_NewFrame ();
    ImGui_ImplGlfw_NewFrame ();

    ImGui::NewFrame ();
}

void loglib::GLFWImGuiOGLWindow::EndFrame ()
{
    ImGui::EndFrame ();
    ImGui::Render ();

    ImGui_ImplOpenGL3_RenderDrawData ( ImGui::GetDrawData () );

    glfwSwapBuffers ( window );
}

void loglib::GLFWImGuiOGLWindow::glfwDropCallback 
( GLFWwindow * window, int count, char const ** files )
{
    if ( GetThis(window).fileDropCallback )
        GetThis(window).fileDropCallback ( { files [0] } );
}
