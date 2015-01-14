#include "Mesh.h"

namespace chrisHit
{
	Mesh::Mesh(const CHvoid *data, CHsizeiptr size, CHsizei count, ShaderProgram *program)
	{
		mesh_count = count;
		mesh_program = program;
		vertex_pos = mesh_program->getAttribLocation("Vertex_Pos");

		CHuint temp_vao;
		glGenVertexArrays(1, &temp_vao);
		mesh_vao.push_back(temp_vao);
		glBindVertexArray(mesh_vao[0]);

		glGenBuffers(1, &mesh_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

		glBindVertexArray(0);

	}

	Mesh::Mesh(const CHvoid *data, CHsizeiptr size, CHsizei count)
	{
		mesh_count = count;
		mesh_program = new ShaderProgram();
		vertex_pos = mesh_program->getAttribLocation("Vertex_Pos");

		CHuint temp_vao;
		glGenVertexArrays(1, &temp_vao);
		mesh_vao.push_back(temp_vao);
		glBindVertexArray(mesh_vao[0]);

		glGenBuffers(1, &mesh_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, mesh_vbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

		glBindVertexArray(0);

	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1,&mesh_vao[0]);
		mesh_vao.clear();

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

}