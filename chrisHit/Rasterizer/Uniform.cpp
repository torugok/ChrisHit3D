#include "Uniform.h"

#include <gtc/matrix_transform.hpp> 
#include <gtx/transform.hpp>

void Uniform::setMat4x4(glm::mat4 &matrix)
{
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, &matrix[0][0]);
}