#pragma once

extern Pine::Application* Pine::CreateApplication();

int main(int argc, char** argv) {

	Pine::Log::Init();
	auto app = Pine::CreateApplication();
	app->Run();
	delete app;
}