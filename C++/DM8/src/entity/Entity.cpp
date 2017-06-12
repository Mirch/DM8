#include "Entity.h"

#include "../game/scene/Scene.h"

namespace DM8
{
	using namespace scene;
	namespace entity
	{
		Entity::Entity(std::string name)
			: m_Name(name)
		{

		}

		Entity::Entity(std::string name, graphics::Sprite* sprite, const math::Mat4& transform)
			: m_Name(name)
		{
			AddComponent(new component::SpriteComponent(sprite, this));
			AddComponent(new component::TransformComponent(transform, this));
			AddComponent(new component::CollisionBox(this));
			Transform = GetComponent<component::TransformComponent>();
		}

		Entity::~Entity()
		{
			for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
			{
				delete it->second;
			}
		}

		void Entity::SetScene(scene::Scene* scene)
		{
			Scene = scene;
		}

		void Entity::AddComponent(component::Component* component)
		{
			m_Components[component->GetName()] = component;
		}

		void Entity::RemoveComponent(std::string name)
		{
			m_Components.erase(name);
		}
		
		void Entity::Start()
		{
			for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
			{
				if (dynamic_cast<component::EntityBehaviour*>(it->second) != 0)
					dynamic_cast<component::EntityBehaviour*>(it->second)->Start();
			}
		}

		void Entity::Update()
		{
			for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
				it->second->Update();
		}

	}
}