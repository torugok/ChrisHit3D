#include "..\chrisHit\chrisHit.h"

using namespace chrisHit;


int main(void)
{
	auto mywindow = new Window(800, 600, "Hello Mesh");

	CHfloat vertices[] = {
		-0.5,0.5,0.0,
		-0.5,-0.5,0.0,
		0.5,-0.5,0.0
	};

	auto *mymesh = new Mesh(vertices, sizeof(vertices), sizeof(vertices) / sizeof(CHfloat) / 3);
	
	while (!mywindow->WindowShouldClose())
	{
		Clear(COLOR_BUFFER | DEPTH_BUFFER);

		mymesh->draw();

		mywindow->MakeLoop();
	}
	delete mymesh;
	mywindow->terminate();
	delete mywindow;
	return 0;
}
