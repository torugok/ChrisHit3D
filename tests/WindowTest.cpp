#include "..\chrisHit\chrisHit.h"


int main(void)
{
	auto mywindow = new chrisHit::Window(800, 600, "Hello World");


	/* Loop until the user closes the window */
	while (!mywindow->WindowShouldClose())
	{
		/* Render here */

		
		/*             */
		mywindow->MakeLoop();
	}

	mywindow->terminate();
	return 0;
}
