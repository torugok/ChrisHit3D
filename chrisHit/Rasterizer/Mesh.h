#ifndef MESH_H
#define MESH_H

#include "..\Base\Common.h"
#include "ShaderProgram.h"

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
		std::vector<GLubyte> indices;

		void addVertex(CHfloat x, CHfloat y, CHfloat z)
		{
			vertices.push_back(Vertex(x, y, z));
		}
		void addIndices(GLubyte x, GLubyte y, GLubyte z)
		{
			indices.push_back(x);
			indices.push_back(y);
			indices.push_back(z);
		}
	};


	class Mesh
	{
	private:
		std::vector<Vertex> vertices;
		std::vector<GLubyte> indices;

		unsigned int mesh_vbo, mesh_vao, mesh_ibo;
		int vertex_pos;

		ShaderProgram *mesh_program;
		void Submit();
	public:
		Mesh(MeshData mesh, ShaderProgram *program);
		Mesh(MeshData mesh);
		~Mesh();
		
		void Draw(glm::mat4 &matrix);
		void drawElements(glm::mat4 &matrix);

		ShaderProgram *getProgram();
	};
}

#endif