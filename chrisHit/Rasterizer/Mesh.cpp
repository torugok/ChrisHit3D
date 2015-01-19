#include "Mesh.h"

namespace chrisHit
{
	void Mesh::Submit()
	{
		glGenVertexArrays(1, &mesh_vao);
		glBindVertexArray(mesh_vao);

		glGenBuffers(1, &mesh_vbo);
		glGenBuffers(1, &mesh_ibo);

		GLuint indices_[] = { 0, 2, 3,
			0, 3, 1 };
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(MeshDecl), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_), indices_, GL_STATIC_DRAW);

		vertex_pos = mesh_program->getAttribLocation("vertex_pos");
		glEnableVertexAttribArray(vertex_pos);

		

		glBindVertexArray(0);
	}


	Mesh::Mesh(MeshDecl mesh)
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

	void Mesh::drawArray(glm::mat4 &matrix)
	{		

		mesh_program->enableProgram();
		glUniformMatrix4fv(glGetUniformLocation(this->mesh_program->getProgramID(), "final_mat"), 1, GL_FALSE, &matrix[0][0]);

		glBindVertexArray(mesh_vao);
		
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glVertexAttribPointer(vertex_pos, 3, GL_FLOAT, GL_FALSE, 0, (CHvoid*)0);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh_ibo);
		//glDrawArrays(GL_TRIANGLES, 0, vertices.size());
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT,0);

		glBindVertexArray(0);
		mesh_program->disableProgram();
	}

	ShaderProgram *Mesh::getProgram()
	{
		return mesh_program;
	}

}