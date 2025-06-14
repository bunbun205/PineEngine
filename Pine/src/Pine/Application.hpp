#pragma once

#include "Core.hpp"

namespace Pine {

class PINE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

}; // Application

Application* CreateApplication();

} // namespace Pine