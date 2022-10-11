cmake_minimum_required ( VERSION 3.24.2 )

project ( LogLib )

add_library ( LogLib )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory ( external/glfw )

include ( "FindOpenGL" )

target_include_directories ( LogLib 
    INTERFACE
        include

    PUBLIC 
        external/imgui
    
    PRIVATE 
        include/LogLib 
        source
        external/glfw/include
        
)

target_link_libraries ( LogLib 
    INTERFACE
    glfw
    OpenGL::GL
)

target_sources ( LogLib
    INTERFACE
        external/imgui/imgui.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_widgets.cpp

    PRIVATE
        source/ImGui.cpp
        source/LogWindow.cpp
)