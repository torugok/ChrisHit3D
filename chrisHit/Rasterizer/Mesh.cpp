#include "Mesh.h"

namespace chrisHit
{
	void Mesh::Submit()
	{
		glGenVertexArrays(1, &mesh_vao);
		glBindVertexArray(mesh_vao);

		glGenBuffers(1, &mesh_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

		glGenBuffers(1, &mesh_ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()* sizeof(GLubyte), &indices[0], GL_STATIC_DRAW);

		vertex_pos = mesh_program->getAttribLocation("vertex_pos");
		glEnableVertexAttribArray(vertex_pos);

		glBindVertexArray(0);
	}


	Mesh::Mesh(MeshData mesh)
	{
		mesh_program = new ShaderProgram();
		this->vertices = mesh.vertices;
		this->indices = mesh.indices;
		this->Submit();
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1,&mesh_vao);

		glDeleteBuffers(1, &mesh_vbo);
		mesh_vbo = 0;

		delete mesh_program;
	}

	void Mesh::Draw(glm::mat4 &matrix)
	{		

		mesh_program->enableProgram();
		glUniformMatrix4fv(glGetUniformLocation(this->mesh_program->getProgramID(), "final_mat"), 1, GL_FALSE, &matrix[0][0]);

		glBindVertexArray(mesh_vao);
		
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glVertexAttribPointer(vertex_pos, 3, GL_FLOAT, GL_FALSE, 0, (CHvoid*)0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh_ibo);
	
		glDrawElements(GL_TRIANGLES,indices.size(), GL_UNSIGNED_BYTE,0);

		glBindVertexArray(0);
		mesh_program->disableProgram();
	}

	ShaderProgram *Mesh::getProgram()
	{
		return mesh_program;
	}

}