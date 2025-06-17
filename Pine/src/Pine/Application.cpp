#include "Events/ApplicationEvent.hpp"
#include "Events/Event.hpp"
#include "Log.hpp"
#include "pinepch.hpp"
#include "Application.hpp"

#include "Pine/Events/ApplicationEvent.hpp"
#include "Pine/Log.hpp"

#include <GLFW/glfw3.h>


namespace Pine {

#define BIND_EVENT_FN(fn) std::bind(&Application::fn, this, std::placeholders::_1)

Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Application::~Application()
{
}

void Application:: PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void Application::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
}

void Application::OnEvent(Event &e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
	
	for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
		(*--it)->OnEvent(e);
		if (e.Handled)
			break;
	}
}

void Application::Run()
{

	while (m_Running) {
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack) {
			layer->OnUpdate();
		}

		m_Window->OnUpdate();
	}

}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

} // namespace Pine