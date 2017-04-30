#pragma once

#include "../../graphics/Sprite.h"
#include "Component.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			class SpriteComponent : public Component
			{
			public:
				graphics::Sprite* m_Sprite;
			public:
				SpriteComponent(graphics::Sprite * sprite);

				static std::string GetStaticName()
				{
					return "Sprite";
				}

				virtual inline std::string GetName() const override { return GetStaticName(); }


			};


		}
	}
}