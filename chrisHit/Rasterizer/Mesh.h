#ifndef MESH_H
#define MESH_H

#include "..\Base\Common.h"
#include "ShaderProgram.h"
#include <vector>
namespace chrisHit
{

	class MeshDecl
	{
	public:
		std::vector<glm::vec3> vertices;
		std::vector<GLuint> indices;
		std::vector<glm::vec3> colors;
		void addVertex(glm::vec3 vec)
		{
			vertices.push_back(vec);
		}
		void addIndices(glm::ivec3 vec)
		{
			indices.push_back(vec.x);
			indices.push_back(vec.y);
			indices.push_back(vec.z);
		}
		void addColor(glm::vec3 vec)
		{
			colors.push_back(vec);
		}

	};


	class Mesh
	{
	private:
		std::vector<glm::vec3> vertices;
		std::vector<GLuint> indices;

		unsigned int mesh_vbo, mesh_vao, mesh_ibo;
		int vertex_pos;

		ShaderProgram *mesh_program;
		void Submit();
	public:
		Mesh(MeshDecl mesh, ShaderProgram *program);
		Mesh(MeshDecl mesh);
		~Mesh();
		
		void drawArray(glm::mat4 &matrix);
		void drawElements(glm::mat4 &matrix);

		ShaderProgram *getProgram();
	};
}

#endif