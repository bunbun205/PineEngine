#include "pinepch.hpp"

#include "Platform/Linux/LinuxWindow.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

namespace Pine {

#ifdef PINE_PLATFORM_WINDOWS
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

#else
	Window* Window::Create(const WindowProps& props)
	{
		return new LinuxWindow(props);
	}
#endif
}