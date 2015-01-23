#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "..\Base\Common.h"
#include "Shader.h"

namespace chrisHit
{
	class ShaderProgram
	{
	private:
		ProgramHandle program;
		Shader *vert, *frag;
	public:
		ShaderProgram(Shader *_vert, Shader *_frag);
		ShaderProgram(const GLchar *vertex_path, const GLchar *fragment_path);
		ShaderProgram();
		~ShaderProgram();
		//void attachVertShader(Shader *vert);
		//void attachFragShader(Shader *frag);

		void enableProgram();
		void disableProgram();

		ProgramHandle getProgramHandle();
		AttribHandle getAttribLocation(const char *name);
		UniformHandle getUniformLocation(const char *name);

		void setUniformMatrix(UniformHandle location, glm::mat4 &matrix);
	};
}

#endif