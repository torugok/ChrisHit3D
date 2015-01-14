#include "Mesh.h"

namespace chrisHit
{
	Mesh::Mesh(const CHvoid *data, CHsizeiptr array_size, CHsizei vertex_count, ShaderProgram *program)
	{
		mesh_count = vertex_count;
		mesh_program = program;
		vertex_pos = mesh_program->getAttribLocation("Vertex_Pos");

		glGenVertexArrays(1, &mesh_vao[0]);
		glBindVertexArray(mesh_vao[0]);

		glGenBuffers(1, &mesh_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glBufferData(GL_ARRAY_BUFFER, array_size, data, GL_STATIC_DRAW);

		glBindVertexArray(0);

	}

	Mesh::Mesh(const CHvoid *data, CHsizeiptr array_size, CHsizei vertex_count)
	{
		mesh_program = new ShaderProgram();
		vertex_pos = mesh_program->getAttribLocation("Vertex_Pos");
		mesh_count = vertex_count;

		glGenVertexArrays(1, &mesh_vao[0]);
		glBindVertexArray(mesh_vao[0]);

		glGenBuffers(1, &mesh_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glBufferData(GL_ARRAY_BUFFER, array_size, data, GL_STATIC_DRAW);

		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1,&mesh_vao[0]);

		glDeleteBuffers(1, &mesh_vbo);
		mesh_vbo = 0;

		mesh_program->deleteProgram();
		mesh_program = 0;
		position_loc = 0;
	}

	void Mesh::draw()
	{		
		mesh_program->enableProgram();
		glBindVertexArray(mesh_vao[0]);

		glVertexAttribPointer(vertex_pos, 3, GL_FLOAT, GL_FALSE, 0, (CHvoid*)0);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_TRIANGLES, 0, mesh_count);

		glBindVertexArray(0);
		mesh_program->disableProgram();
	}

	ShaderProgram *Mesh::getProgram()
	{
		return mesh_program;
	}

}