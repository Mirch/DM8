#pragma once

#include "Component.h"
#include "../../math/Mat4.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			class TransformComponent : public Component
			{
			public:
				math::Mat4 m_Transform;
			public:
				TransformComponent(const math::Mat4& transform);

				static std::string GetStaticName()
				{
					return "Transform";
				}

				virtual inline std::string GetName() const override { return GetStaticName(); }


			};


		}
	}
}