#pragma once

#include <string>
#include <unordered_map>

#include "component/Components.h"

namespace DM8
{
	namespace entity
	{
		class Entity
		{
		protected:
			std::string m_Name;
			std::unordered_map<std::string, component::Component*> m_Components;
		public:
			Entity();
			Entity(graphics::Sprite* sprite, const math::Mat4& transform = math::Mat4::Identity());

			void AddComponent(component::Component* component);
			void RemoveComponent(std::string name);

			void Update();

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