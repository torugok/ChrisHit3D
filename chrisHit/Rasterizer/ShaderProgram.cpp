#include "ShaderProgram.h"

namespace chrisHit
{

	ShaderProgram::ShaderProgram(Shader *_vert, Shader *_frag)
	{
		vert = _vert;
		frag = _frag;

		this->program = glCreateProgram();
		glAttachShader(this->program, vert->getShaderHandle());
		glAttachShader(this->program, frag->getShaderHandle());
		
		glLinkProgram(this->program);
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
			"frag_color = vec4(1.0f, 0.5f, 1.0f, 1.0f);\n"
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

		this->program = glCreateProgram();
		glAttachShader(this->program, vert->getShaderHandle());
		glAttachShader(this->program, frag->getShaderHandle());

		glLinkProgram(this->program);

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

		this->program = glCreateProgram();
		glAttachShader(this->program, vert->getShaderHandle());
		glAttachShader(this->program, frag->getShaderHandle());

		glLinkProgram(this->program);
		delete vert;
		delete frag;
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(this->program);
	}

	void ShaderProgram::enableProgram()
	{
		glUseProgram(this->program);
	}

	void ShaderProgram::disableProgram()
	{
		glUseProgram(0);
	}

	ProgramHandle ShaderProgram::getProgramHandle()
	{
		return this->program;
	}

	AttribHandle ShaderProgram::getAttribLocation(const char *name)
	{
		return glGetAttribLocation(this->program, name);
	}

	UniformHandle ShaderProgram::getUniformLocation(const char *name)
	{
		return glGetUniformLocation(this->program, name);
	}

	void ShaderProgram::setUniformMatrix(UniformHandle location, glm::mat4 &matrix)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
	}
}
