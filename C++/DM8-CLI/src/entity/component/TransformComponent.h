#pragma once

#include "Component.h"

namespace DM8CLI
{
	namespace entity
	{
		namespace component
		{

			public ref class TransformComponent : public Component
			{
			private:
				TransformComponent(DM8::entity::component::TransformComponent* instance);
			public:
				TransformComponent();

				static String^ GetStaticName()
				{
					return gcnew String(DM8::entity::component::TransformComponent::GetStaticName().c_str());
				}

				virtual inline String^ GetName() override { return GetStaticName(); }

			};

		}
	}
}