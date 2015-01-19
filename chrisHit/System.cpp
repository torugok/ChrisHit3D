#include "System.h"
namespace chrisHit
{
	void System::Begin(int x, int y, const char *name)
	{
		window = new Window(x, y,name);
	}

	Window *System::getWindow()
	{
		return window;
	}

}