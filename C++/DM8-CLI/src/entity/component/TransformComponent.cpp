#include "TransformComponent.h"


namespace DM8CLI
{
	namespace entity
	{
		namespace component
		{

			TransformComponent::TransformComponent()
				: Component()
			{
			}

			TransformComponent::TransformComponent(DM8::entity::component::TransformComponent* instance)
				: Component(instance)
			{
			}

		}
	}
}