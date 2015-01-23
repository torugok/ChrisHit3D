
#ifndef SHADER_H
#define SHADER_H

#include "..\Base\Common.h"

namespace chrisHit
{
	class Shader
	{
	private:
		ShaderHandler shaderID;
	public:
		Shader(CHenum type, const char *data);
		~Shader();

		ShaderHandler getShaderHandle();
		//void compileShader();
	};
}
#endif