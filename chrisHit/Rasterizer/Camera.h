#ifndef CAMERA_H
#define CAMERA_H

#include <glm.hpp>


namespace chrisHit
{

	class Camera
	{
	private:
		glm::mat4 *Projection;
		glm::mat4 *View;
	public:
		Camera(glm::mat4 *Projection, glm::mat4 *View);
		void yaw(float angle);
		void pitch(float angle);
		void roll(float angle);

	};
}


#endif