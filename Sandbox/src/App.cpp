#include "pinepch.hpp"
#include <Pine.hpp>

class ExampleLayer : public Pine::Layer {
public:
	ExampleLayer() : Pine::Layer("Example") {}

	void OnUpdate() override {
		PINE_INFO("ExampleLayer updating");
	}

	void OnEvent(Pine::Event& event) override {
		PINE_TRACE("Event: {0}", event.ToString());
	}
};

class App : public Pine::Application {

public:
	App() {
		// Initialization code can go here
		PushLayer(new ExampleLayer());
	}

	~App() {
		// Cleanup code can go here
	}
};

Pine::Application* Pine::CreateApplication() {
	return new App();
}