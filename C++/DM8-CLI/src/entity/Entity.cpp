#include "Entity.h"

namespace DM8CLI
{
	namespace entity
	{

		Entity::Entity()
			: DMManagedObject()
		{
		}

		Entity::Entity(DM8::entity::Entity* instance)
			: DMManagedObject(instance)
		{
		}

		Entity::Entity(graphics::Sprite^ sprite, math::Mat4^ transform)
		{
			m_Instance = new DM8::entity::Entity((DM8::graphics::Sprite*)(sprite->GetHandle()), *(transform->GetHandle()));
		}

		void Entity::AddComponent(component::Component^ component)
		{
			m_Instance->AddComponent(component->GetHandle());
		}

		void Entity::RemoveComponent(String^ name)
		{
			m_Instance->RemoveComponent(string_to_char_array(name));
		}



	}
}