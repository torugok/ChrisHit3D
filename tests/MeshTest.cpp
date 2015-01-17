#include "..\chrisHit\chrisHit.h"

using namespace chrisHit;

class _scene
{
private:
	Mesh *mymesh;
	Mesh *mymesh2;
public:
	void init(){
		CHfloat vertices[] = {
			-0.8f, 0.8f, 0.0f,   
			-0.8f, -0.8f, 0.0f,  
			0.8f, -0.8f, 0.0f,
		};

		CHfloat vertices2[] = {
			0.8f, 0.8f, 0.0f,   
			-0.8f, 0.8f, 0.0f,   
			0.8f, -0.8f, 0.0f,  
		};

		auto *pr = new ShaderProgram("assets/vert.glsl", "assets/frag.glsl");

		mymesh = new Mesh(vertices, sizeof(vertices), sizeof(vertices) / sizeof(CHfloat) / 3,pr);
		mymesh2 = new Mesh(vertices2, sizeof(vertices2), sizeof(vertices2) / sizeof(CHfloat) / 3);
	}

	~_scene()
	{
		delete mymesh, mymesh2;
	}
	
	void draw()
	{
		
		mymesh->drawArray();
		mymesh2->drawArray();
	}
};

int main(void)
{
	auto mywindow = new Window(800, 600, "Hello Mesh");
	
	auto *sce = new _scene();
	sce->init();

	while (!mywindow->WindowShouldClose())
	{
		Clear(COLOR_BUFFER | DEPTH_BUFFER);

		sce->draw();

		mywindow->MakeLoop();
	}
	delete sce;
	mywindow->terminate();
	delete mywindow;
	return 0;
}
