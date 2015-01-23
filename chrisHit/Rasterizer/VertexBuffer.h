
#include "..\Base\Common.h"

namespace chrisHit
{
	class VertexBuffer
	{
	private:
		GLuint vb;
		GLenum target;
	public:
		VertexBuffer(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
		~VertexBuffer();

		void reBind();
	};
}	