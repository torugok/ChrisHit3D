#ifndef WINDOW_H
#include <GLFW\glfw3.h>


namespace chrisHit
{


	class Window
	{
	private:
		GLFWwindow *window;

	public:
		Window(int x, int y, const char *title);
		bool WindowShouldClose();
		void MakeLoop();
		void terminate();
	};

#endif // !WINDOW_H

}