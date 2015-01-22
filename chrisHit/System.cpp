#include "System.h"

namespace chrisHit
{
	System System::system;

	void System::Begin(int x, int y, const char *name)
	{
		window = new Window(x, y, name);
		std::cout << "OpenGL actual: " 
			<< glGetString(GL_VERSION) << " GLSL version: " 
			<< glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	}

	void System::MakePlatform(Framework *framework)
	{
	#if defined(WIN32)
		framework->init();
		double lastTime = glfwGetTime();
		while (!this->window->WindowShouldClose())
		{
			double currentTime = glfwGetTime();
			float deltaTime = float(currentTime - lastTime);
			framework->Loop(deltaTime);
			this->window->MakeLoop();
		}
		this->Close();
	#endif
	}

	void System::Close()
	{
		this->window->terminate();
	}

	System &System::getInstance()
	{
		return system;
	}

	Window *System::getWindow()
	{
		return window;
	}

}