#include "LogWindow.hpp"

loglib::LogWindow::LogWindow ()
{
    glfwInit ();
    
    window = glfwCreateWindow ( 500, 500, "log", nullptr, nullptr );
}

loglib::LogWindow::~LogWindow ()
{
    glfwDestroyWindow ( window );
}

void loglib::LogWindow::Update ()
{
    glfwPollEvents ();
}