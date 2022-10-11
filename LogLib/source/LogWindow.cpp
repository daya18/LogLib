#include "LogWindow.hpp"

#include "ImGui.hpp"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include "Log.hpp"

loglib::LogWindow::LogWindow ( Log const & log )
: log ( &log )
{
    glfwInit ();

    window = glfwCreateWindow ( 500, 500, "log", nullptr, nullptr );
    glfwMakeContextCurrent ( window );

    imguiContext = ImGui::CreateContext ();
    
    ImGui_ImplGlfw_InitForOpenGL ( window, true );
    ImGui_ImplOpenGL3_Init ();
    
    ImGui::StyleColorsDark ();
}

loglib::LogWindow::~LogWindow ()
{
    glfwDestroyWindow ( window );
    glfwTerminate ();
}

bool loglib::LogWindow::ShouldClose () const
{
    return glfwWindowShouldClose ( window );
}

void loglib::LogWindow::Update ()
{
    glfwPollEvents ();

    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    ImGui_ImplOpenGL3_NewFrame ();
    ImGui_ImplGlfw_NewFrame ();

        ImGui::NewFrame ();
        
        RenderImGui ( *log, true );

        ImGui::EndFrame ();
        ImGui::Render ();

    ImGui_ImplOpenGL3_RenderDrawData ( ImGui::GetDrawData () );

    glfwSwapBuffers ( window );
}