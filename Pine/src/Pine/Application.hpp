#pragma once

#include "Window.hpp"
#include "Pine/LayerStack.hpp"
#include "Events/ApplicationEvent.hpp"

namespace Pine {

class PINE_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

	void OnEvent(Event &e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);

private:
	bool OnWindowClose(WindowCloseEvent& e);
	std::unique_ptr<Window> m_Window;
	bool m_Running = true;
	LayerStack m_LayerStack;

}; // Application

Application* CreateApplication();

} // namespace Pine