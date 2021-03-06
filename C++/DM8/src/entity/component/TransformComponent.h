#pragma once

#include "Component.h"
#include "../../math/Mat4.h"
#include "../../math/Vec2.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			class TransformComponent : public Component
			{
			public:
				math::Vec3 m_Position;
				math::Vec2 m_Size;
				float m_Angle;
			public:
				math::Mat4 m_Transform;
			public:
				TransformComponent(const math::Mat4& transform, Entity* entity);

				static std::string GetStaticName()
				{
					return "Transform";
				}

				virtual inline std::string GetName() const override { return GetStaticName(); }

				void Translate(const math::Vec3& vector);
				void Rotate(float angle);


			};


		}
	}
}