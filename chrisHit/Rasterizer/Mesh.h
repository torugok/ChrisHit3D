#ifndef MESH_H
#define MESH_H

#include "..\Base\Common.h"
#include "ShaderProgram.h"
#include "VertexBuffer.h"

namespace chrisHit
{
	struct Vertex
	{
		GLfloat x, y, z;
		Vertex(GLfloat x, GLfloat y, GLfloat z)
		{
			this->x = x; 
			this->y = y; 
			this->z = z;
		}
	};

	struct MeshData
	{
		std::vector<Vertex> vertices;
		std::vector<GLushort> indices;

		void addVertex(CHfloat x, CHfloat y, CHfloat z)
		{
			vertices.push_back(Vertex(x, y, z));
		}

		void addIndices(GLushort x, GLushort y, GLushort z)
		{
			indices.push_back(x);
			indices.push_back(y);
			indices.push_back(z);
		}

		void clear()
		{
			vertices.clear();
			indices.clear();
		}
	};


	class Mesh
	{
	private:
		VertexBuffer *mesh_vbo, *mesh_ibo;
		GLuint mesh_vao;
		GLsizei count;
		int vertex_pos;
		int matrix_pos;

		ShaderProgram *mesh_program;

	public:
		Mesh(MeshData *mesh, ShaderProgram *program);
		Mesh(MeshData *mesh);
		~Mesh();
		
		void Draw(glm::mat4 &matrix);

		ShaderProgram *getProgram();
	};
}

#endif