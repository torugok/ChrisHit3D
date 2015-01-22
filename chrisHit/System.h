#include "SceneManager.h"
#include "Window\Window.h"
#include "Framework.h"

namespace chrisHit
{
	class System
	{
	private:
		//System();
		static System system;
		//Rasterizer *raster;
		SceneManager *scemgr;
		//PhysicsManager *phymgr;
		Window *window;

		float delta;

	public:
		static System &getInstance();
		void Begin(int x, int y, const char *name);

		void init();
		void Loop(float delta);

		void MakePlatform(Framework *framework);
		void Close();

		//Rasterizer *getRasterizer();
		SceneManager *getSceneManager();
		Window *getWindow();
		//PhysicsManager *getPhysicsManager();
	};
}
