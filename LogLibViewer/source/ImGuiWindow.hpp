#pragma once

namespace loglib
{
    class ImGuiWindow
    {
    public:
        virtual void BeginFrame () = 0;
        virtual void EndFrame () = 0;
    };
}