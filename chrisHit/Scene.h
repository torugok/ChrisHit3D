#ifndef SCENE_H
#define SCENE_H

#include "Base\Common.h"
#include "Rasterizer\Camera.h"
#include "Node.h"
#include "Rasterizer\Mesh.h"

namespace chrisHit
{
	class Scene
	{
	private:
		Camera *active;
		std::map<const char *, Node*> nodes;

	public:
		Node *createNode(const char*name, Mesh *mesh);

		Camera *getActiveCamera();
		void setActiveCamera(Camera *cam);

	};
}


#endif