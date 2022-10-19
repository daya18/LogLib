#pragma once

#include <functional>
#include <string>

namespace loglib
{
    // Interface to be used by ImGuiRenderer
    class ImGuiWindow
    {
    public:
        using FileDropCallback = std::function < void ( std::string const & ) >;

        virtual void BeginFrame () = 0;
        virtual void EndFrame () = 0;
        virtual void SetFileDropCallback ( FileDropCallback ) = 0;
    };
}