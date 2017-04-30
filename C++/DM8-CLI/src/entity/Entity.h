#pragma once

#include "../DMManagedObject.h"

#include "../graphics/Sprite.h"
#include "../math/Mat4.h"
#include "component/Component.h"

using namespace System;

namespace DM8CLI
{
	namespace entity
	{
		public ref class Entity : public DMManagedObject<DM8::entity::Entity>
		{
		private:
			Entity(DM8::entity::Entity* instance);
		public:
			Entity();
			Entity(graphics::Sprite^ sprite, math::Mat4^ transform);

			void AddComponent(component::Component^ component);
			void RemoveComponent(String^ name);

			template<typename T>
			T* GetComponent()
			{
				return m_Instance->GetComponent<typeof(gcnew T()->GetHandle())>();
			}


		};
	}
}