#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "..\Base\Common.h"
#include "Shader.h"
#include "Uniform.h"

namespace chrisHit
{
	class ShaderProgram
	{
	private:
		CHuint program;
		Shader *vert, *frag;
	public:
		ShaderProgram(Shader *_vert, Shader *_frag);
		ShaderProgram();
		void deleteProgram();
		~ShaderProgram();
		//void attachVertShader(Shader *vert);
		//void attachFragShader(Shader *frag);

		void enableProgram();
		void disableProgram();

		CHuint getProgramID();
		CHint getAttribLocation(const char *name);
		Uniform *getUniform(const char *name);
	};
}

#endif