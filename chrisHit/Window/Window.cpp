#include "..\Base\Common.h"
#include "Window.h"

namespace chrisHit
{
#if defined(WIN32)
	Window::Window(int x, int y, const char *title)
	{
		glfwInit();

		#if defined(GL_3) 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glewExperimental = GL_TRUE;
		#endif
		window = glfwCreateWindow(x, y, title, NULL, NULL);
		if (!window)
		{
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		glewInit();
	}

	int Window::WindowShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	//Render before this
	void Window::MakeLoop()
	{
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void Window::terminate()
	{
		glfwTerminate();
	}
}
#endif