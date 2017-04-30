#include "TransformComponent.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			TransformComponent::TransformComponent(const math::Mat4& transform)
				: m_Transform(transform)
			{
			}
		}
	}
}