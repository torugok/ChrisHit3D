#ifndef WINDOW_H
#define WINDOW_H



namespace chrisHit
{
#if defined(WIN32)
#include <GLFW\glfw3.h>
	class Window
	{
	private:
		GLFWwindow *window;

	public:
		Window(int x, int y, const char *title);
		int WindowShouldClose();
		void MakeLoop();
		void terminate();
	};
#endif
}

#endif // !WINDOW_H
