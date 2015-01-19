#include "..\chrisHit\chrisHit.h"
#include <iostream>
#include <memory>
using namespace chrisHit;




int main(void)
{
	using namespace glm;
	using namespace std;

	auto mywindow = new Window(800, 600, "Hello Mesh");
	
	/*vector<Vertex> v;
	Vertex v1; v1.vertices = vec3(-0.8, 0.8, 0.0);
	v.push_back(v1);

	Vertex v2; v2.vertices = vec3(-0.8, -0.8, 0.0);
	v.push_back(v2);

	Vertex v3; v3.vertices = vec3(0.8, -0.8, 0.0);
	v.push_back(v3);
	*/

	auto malha = MeshDecl();


	malha.addVertex(vec3(-0.8, 0.8, 0.0));
	malha.addVertex(vec3(0.8, 0.8, 0.0));
	malha.addVertex(vec3(0.8, -0.8, 0.0));
	malha.addVertex(vec3(0.8, -0.8, 0.0));

	malha.addIndices(ivec3( 0, 2, 3));
	malha.addIndices(ivec3(0, 3, 1));

	auto *mesh = new Mesh(malha);

	mat4 perspective_ = perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	mat4 camera = lookAt(glm::vec3(4, 3, 3),glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)  );
	mat4 object = mat4(1.0f);
	mat4 final_mat = perspective_ * camera * object;
	
	while (!mywindow->WindowShouldClose())
	{
		Clear(COLOR_BUFFER | DEPTH_BUFFER);
		mesh->drawArray(final_mat);
		mywindow->MakeLoop();
	}


	mywindow->terminate();
	delete mywindow;
	return 0;
}
