#include "..\chrisHit\chrisHit.h"
#include <iostream>
#include <memory>
using namespace chrisHit;
#include <iostream>
#include <string>
using namespace glm;
using namespace std;
#include "..\chrisHit\Base\POD\PVRTModelPOD.h"

class MyGame : public Framework
{

private:
	Mesh *mesh;
	mat4 final_mat;

public:
	MyGame() : mesh(0), final_mat(0)
	{

	}

	~MyGame()
	{
		delete mesh;
	}

	void init()
	{
		auto malha = MeshData();

		malha.addVertex(-1.0f, 1.0f, 0.0f);
		malha.addVertex(1.0f, 1.0f, 0.0f);
		malha.addVertex(-1.0f, -1.0f, 0.0f);
		malha.addVertex(1.0f, -1.0f, 0.0f);

		malha.addIndices(0, 2, 3);
		malha.addIndices(0, 3, 1);

		mesh = new Mesh(&malha);
		malha.clear();

		mat4 perspective_ = perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		mat4 camera = lookAt(glm::vec3(4, 3, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		mat4 object = mat4(1.0f);
		final_mat = perspective_ * camera * object;
		RenderFunctions::setBackGroundColor(0.5f, 1.0f, 0.2f, 1.0f);
	}

	void Loop(float delta)
	{
		RenderFunctions::ClearBuffer(COLOR_BUFFER | DEPTH_BUFFER);
		mesh->Draw(final_mat);
	}

};

int main(void)
{
	CPVRTModelPOD m_scene;
	Framework *instance = new MyGame();
	System *sys = &System::getInstance();

	sys->Begin(800,600,"Hello Window");
	sys->MakePlatform(instance);
	sys->Close();

	delete instance;
	return 0;
}
