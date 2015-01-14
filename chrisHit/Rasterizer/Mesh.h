#ifndef MESH_H
#define MESH_H

#include "..\Base\Common.h"
#include "ShaderProgram.h"
#include <vector>
namespace chrisHit
{
	class Mesh
	{
	private:
		CHint vertex_pos;
		CHint position_loc;
		CHuint mesh_vbo;
		CHsizei mesh_count;
		//CHfloat *mesh_data;
		ShaderProgram *mesh_program;
		std::vector<CHuint> mesh_vao;
	public:
		Mesh(const CHvoid *data, CHsizeiptr size, CHsizei count,  ShaderProgram *program);
		Mesh(const CHvoid *data, CHsizeiptr size, CHsizei count);
		~Mesh();
		void draw();
	};
}

#endif