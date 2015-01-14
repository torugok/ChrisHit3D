#include "ShaderProgram.h"

#if defined(GL_3)
const char* default_vertexsrc = "#version 330 core\n"
"layout (location = 0) in vec3 Vertex_Pos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(Vertex_Pos, 1.0);\n"
"}\0";
const char* default_fragsrc = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 1.0, 1.0f, 1.0f);\n"
"}\n\0";
#else
const char* default_vertexsrc =
"#version 120\n"
"attribute vec3 Vertex_Pos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(Vertex_Pos, 1.0);\n"
"}\0";
const char* default_fragsrc = 
"#version 120\n"
"void main()\n"
"{\n"
"gl_FragColor = vec4(1.0f, 1.0, 1.0f, 1.0f);\n"
"}\n\0";
#endif




ShaderProgram::ShaderProgram(Shader *_vert, Shader *_frag)
{
	vert = _vert;
	frag = _frag;

	program = glCreateProgram();
	glAttachShader(program, vert->getShaderID());
	glAttachShader(program, frag->getShaderID());
	
	glLinkProgram(program);
	vert->deleteShader();
	frag->deleteShader();
}

ShaderProgram::ShaderProgram()
{
	
	vert = new Shader(VERTEX_SHADER, default_vertexsrc);
	frag = new Shader(FRAGMENT_SHADER, default_fragsrc);

	program = glCreateProgram();
	glAttachShader(program, vert->getShaderID());
	glAttachShader(program, frag->getShaderID());
	
	glLinkProgram(program);
	vert->deleteShader();
	frag->deleteShader();

}

void ShaderProgram::deleteProgram()
{
	glDeleteProgram(program);
	
}

ShaderProgram::~ShaderProgram()
{
	deleteProgram();
}

void ShaderProgram::enableProgram()
{
	glUseProgram(program);
}

void ShaderProgram::disableProgram()
{
	glUseProgram(0);
}

CHuint ShaderProgram::getProgramID()
{
	return program;
}

CHint ShaderProgram::getAttribLocation(const char *name)
{
	return glGetAttribLocation(program, name);
}
