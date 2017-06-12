#pragma once

#include <string>
#include <unordered_map>

#include "component/Components.h"

#include <vector>

namespace DM8
{
	namespace scene
	{
		class Scene;
	}

	namespace entity
	{

		class Entity
		{
		public:
			component::TransformComponent* Transform;
			scene::Scene* Scene;
		protected:
			std::string m_Name;
			std::unordered_map<std::string, component::Component*> m_Components;
		public:
			Entity(std::string name);
			Entity(std::string name, graphics::Sprite* sprite, const math::Mat4& transform = math::Mat4::Identity());
			~Entity();

			void SetScene(scene::Scene* scene);

			void AddComponent(component::Component* component);
			void RemoveComponent(std::string name);

			void Start();
			void Update();

			inline std::string GetName() const { return m_Name; }

			template<typename T>
			T* GetComponent()
			{
				std::string name = T::GetStaticName();
				auto it = m_Components.find(name);
				if (it == m_Components.end())
					return nullptr;
				return (T*)it->second;
			}


		};


	}
}