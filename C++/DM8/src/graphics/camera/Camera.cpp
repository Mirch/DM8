#include "Camera.h"


namespace DM8
{
	namespace graphics
	{
		namespace camera
		{
			Camera::Camera(const math::Mat4& projectionMatrix)
			{
				m_ProjectionMatrix = projectionMatrix;
				m_Position = math::Vec3();
				m_Rotation = math::Vec3();
			}

		}
	}
}