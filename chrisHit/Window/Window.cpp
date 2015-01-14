
#include "..\Base\Common.h"
#include "Window.h"
namespace chrisHit
{

	Window::Window(int x, int y, const char *title)
	{
		glfwInit();

		#if defined(GL_3) 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		#endif
		window = glfwCreateWindow(x, y, title, NULL, NULL);
		if (!window)
		{
			glfwTerminate();
		}
		glfwMakeContextCurrent(window);
		glewExperimental = GL_TRUE;
		glewInit();
	}

	bool Window::WindowShouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	void Window::MakeLoop()
	{
		//Render before this
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void Window::terminate()
	{
		glfwTerminate();
	}
}