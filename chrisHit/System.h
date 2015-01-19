#include "SceneManager.h"
#include "Window\Window.h"

namespace chrisHit
{
	class System
	{
	private:
		System();
		//Rasterizer *raster;
		SceneManager *scemgr;
		//PhysicsManager *phymgr;
		Window *window;
	public:
		void Begin(int x, int y, const char *name);
		//Rasterizer *getRasterizer();
		SceneManager *getSceneManager();
		Window *getWindow();
		//PhysicsManager *getPhysicsManager();
	};
}
