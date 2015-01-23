#include "Mesh.h"


namespace chrisHit
{

	Mesh::Mesh(MeshData *mesh)
	{
		mesh_program = new ShaderProgram();
		count = mesh->indices.size();

		// Vertex arrays
		glGenVertexArrays(1, &mesh_vao);
		glBindVertexArray(mesh_vao);

		// Vertex buffer
		mesh_vbo = new VertexBuffer(GL_ARRAY_BUFFER, count*sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

		// Index buffer
		mesh_ibo = new VertexBuffer(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLushort), &mesh->indices[0], GL_STATIC_DRAW);

		// Get and enable vertex attrib
		vertex_pos = mesh_program->getAttribLocation("vertex_pos");
		glEnableVertexAttribArray(vertex_pos);

		// Get uniform matrix location
		matrix_pos = mesh_program->getUniformLocation("final_mat");

		// Back to initial states
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	Mesh::~Mesh()
	{
		glDeleteVertexArrays(1,&mesh_vao);
		delete mesh_program, mesh_vbo, mesh_ibo;
	}

	void Mesh::Draw(glm::mat4 &matrix)
	{		
		// Use program for next draw calls
		mesh_program->enableProgram();

		// Send matrix 4x4 to an uniform in current program
		glUniformMatrix4fv(matrix_pos, 1, GL_FALSE, &matrix[0][0]);

		// Bind vertex array
		glBindVertexArray(mesh_vao);

		// Bind buffer
		mesh_vbo->reBind();

		// Send to attrib vertex data
		glVertexAttribPointer(vertex_pos, 3, GL_FLOAT, GL_FALSE, 0, (CHvoid*)0);

		// Bind index buffer
		mesh_ibo->reBind();
		
		// Draw triangles!!!
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, 0);

		// Back to initial state
		glBindVertexArray(0);
		mesh_program->disableProgram();
	}

	ShaderProgram *Mesh::getProgram()
	{
		return mesh_program;
	}

}