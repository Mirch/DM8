#pragma once

#include "../../math/DMmath.h"

namespace DM8
{
	namespace graphics
	{
		namespace camera
		{
			class Camera
			{
			protected:
				math::Mat4 m_ProjectionMatrix;
				math::Vec3 m_Position, m_Rotation;
			public:
				Camera(const math::Mat4& projectionMatrix);


				inline void SetPosition(const math::Vec3& position) { m_Position = position; }
				inline const math::Vec3& GetPosition() const { return m_Position; }

				inline void SetRotation(const math::Vec3& rotation) { m_Rotation = rotation; }
				inline const math::Vec3& GetRotation() const { return m_Rotation; }

				inline void SetProjectionMatrix(const math::Mat4& projectionMatrix) { m_ProjectionMatrix = projectionMatrix; }
				inline const math::Mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }

				inline void Translate(const math::Vec3& translation) { m_Position += translation; }
				inline void Rotate(const math::Vec3& rotation) { m_Rotation += rotation; }


			};
		}
	}
}