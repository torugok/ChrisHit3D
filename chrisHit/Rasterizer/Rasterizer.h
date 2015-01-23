#include "Shader.h"
#include "ShaderProgram.h"
#include "Mesh.h"

namespace chrisHit
{
	namespace RenderFunctions
	{
		void ClearBuffer(GLbitfield mask)
		{
			glClear(mask);
		}

		void setBackGroundColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a)
		{
			glClearColor(r, g, b, a);
		}
	}
}