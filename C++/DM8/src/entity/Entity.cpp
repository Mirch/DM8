#include "Entity.h"



namespace DM8
{
	namespace entity
	{
		Entity::Entity()
		{

		}

		Entity::Entity(graphics::Sprite* sprite, const math::Mat4& transform)
		{
			AddComponent(new component::SpriteComponent(sprite));
			AddComponent(new component::TransformComponent(transform));
		}

		void Entity::AddComponent(component::Component* component)
		{
			m_Components[component->GetName()] = component;
		}

		void Entity::RemoveComponent(std::string name)
		{
			m_Components.erase(name);
		}

		void Entity::Update()
		{

		}

	}
}