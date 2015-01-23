#include "VertexBuffer.h"

namespace chrisHit
{
	VertexBuffer::VertexBuffer(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
	{
		glGenBuffers(1, &vb);
		glBindBuffer(target, vb);
		glBufferData(target, size, data, usage);
		this->target = target;
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &vb);
		this->vb = NULL;
		this->target = NULL;
	}

	void VertexBuffer::reBind()
	{
		glBindBuffer(this->target, vb);
	}
}