cmake_minimum_required ( VERSION 3.24.2 )

project ( LogLibViewer )

set ( CMAKE_CXX_STANDARD 17 )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory ( external/glfw )

include ( "FindOpenGL" )

add_executable ( LogLibViewer )

target_include_directories ( LogLibViewer
    PUBLIC 
        external/imgui

    PRIVATE
        source
        external/glfw/include
        external/imgui/backends
)

target_link_libraries ( LogLibViewer
    PRIVATE
    glfw
    OpenGL::GL
    LogLib
)

target_sources ( LogLibViewer
    PRIVATE
        external/imgui/imgui.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp

    PRIVATE
        #ImGui
        source/GLFWImGuiOGLWindow.cpp
        source/ImGuiRenderer.cpp
        source/LogLibViewer.cpp
        
        source/main.cpp
)