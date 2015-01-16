#include "..\Base\Common.h"

class Uniform
{
private:
	CHint uniformID;
public:
	Uniform(CHint id) : uniformID(id){};
	void setMat4x4(glm::mat4 &matrix);
};