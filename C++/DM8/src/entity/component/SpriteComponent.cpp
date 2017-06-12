#include "SpriteComponent.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			SpriteComponent::SpriteComponent(graphics::Sprite* sprite, Entity* entity)
				: m_Sprite(sprite), Component(entity)
			{
			}
		}
	}
}