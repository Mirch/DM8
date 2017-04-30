#include "SpriteComponent.h"


namespace DM8CLI
{
	namespace entity
	{
		namespace component
		{

			SpriteComponent::SpriteComponent()
				: Component()
			{
			}

			SpriteComponent::SpriteComponent(DM8::entity::component::SpriteComponent* instance)
				: Component(instance)
			{
			}

		}
	}
}