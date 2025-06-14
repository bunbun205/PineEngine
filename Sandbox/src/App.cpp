#include <Pine.hpp>

class App : public Pine::Application {

public:
	App() {
		// Initialization code can go here
	}

	~App() {
		// Cleanup code can go here
	}
};

Pine::Application* Pine::CreateApplication() {
	return new App();
}