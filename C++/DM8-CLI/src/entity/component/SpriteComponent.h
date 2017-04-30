#pragma once

#include "Component.h"

namespace DM8CLI
{
	namespace entity
	{
		namespace component
		{

			public ref class SpriteComponent : public Component
			{
			private:
				SpriteComponent(DM8::entity::component::SpriteComponent* instance);
			public:
				SpriteComponent();

				static String^ GetStaticName()
				{
					return gcnew String(DM8::entity::component::SpriteComponent::GetStaticName().c_str());
				}

				virtual inline String^ GetName() override { return GetStaticName(); }

			};

		}
	}
}