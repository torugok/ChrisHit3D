#version 330 core

in vec3 vertex_pos;
uniform mat4 final_mat;

void main()
{
	gl_Position = final_mat*vec4(vertex_pos,1.0f);
}