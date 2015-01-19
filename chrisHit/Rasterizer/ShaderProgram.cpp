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
		delete vert;
		delete frag;
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
			"in vec3 vertex_pos;\n"
			"uniform mat4 final_mat;\n"
			"void main()\n"
			"{\n"
			"gl_Position = final_mat*vec4(vertex_pos, 1.0f);\n"
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
		delete vert;
		delete frag;
	}

	ShaderProgram::ShaderProgram(const GLchar *vertex_path, const GLchar *fragment_path)
	{
		
		auto *vert_gl = new file_reader(vertex_path);
		auto *frag_gl = new file_reader(fragment_path);

		vert = new Shader(VERTEX_SHADER, vert_gl->c_str());
		frag = new Shader(FRAGMENT_SHADER, frag_gl->c_str());

		delete vert_gl, frag_gl;

		program = glCreateProgram();
		glAttachShader(program, vert->getShaderID());
		glAttachShader(program, frag->getShaderID());

		glLinkProgram(program);
		delete vert;
		delete frag;
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(program);
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

	void ShaderProgram::setUniformMatrix(const char *name, glm::mat4 &matrix)
	{
		this->enableProgram();
		glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, &matrix[0][0]);
		this->disableProgram();
	}
}
