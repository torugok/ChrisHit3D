#include "ShaderProgram.h"

namespace chrisHit
{

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

#if defined(GL_3) || defined(GL_ES_3)
		const char* default_vertexsrc =
			#if defined(GL_ES_3)
				"#version 300 es\n"
			#else
				"#version 330 core\n"
			#endif
			"in vec3 Vertex_Pos;\n"
			"void main()\n"
			"{\n"
			"gl_Position = vec4(Vertex_Pos, 1.0f);\n"
			"}\0";
		const char* default_fragsrc =
			#if defined(GL_ES_3)
				"#version 300 es\n"
			#else
				"#version 330 core\n"
			#endif
			"out vec4 frag_color;\n"
			"void main()\n"
			"{\n"
			"frag_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
			"}\n\0";
#else
		const char* default_vertexsrc =
			#if defined(GL_ES_2)
				"#version 100\n"
			#else
				"#version 120\n"
			#endif
			"attribute vec3 Vertex_Pos;\n"
			"void main()\n"
			"{\n"
			"gl_Position = vec4(Vertex_Pos, 1.0);\n"
			"}\0";
		const char* default_fragsrc =
			#if defined(GL_ES_2)
				"#version 100\n"
			#else
				"#version 120\n"
			#endif
			"void main()\n"
			"{\n"
			"gl_FragColor = vec4(1.0f, 1.0, 1.0f, 1.0f);\n"
			"}\n\0";
#endif

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

	CHint ShaderProgram::getUniformLocation(const char *name)
	{
		return glGetUniformLocation(program, name);
	}
}