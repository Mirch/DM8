#pragma once
#include "Component.h"
#include "TransformComponent.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{

			class EntityBehaviour : public Component
			{
			public:
				std::string m_Name;
				TransformComponent* Transform;
			public:
				EntityBehaviour(std::string name, Entity* entity);

				virtual void Start();
				virtual void Update();

				virtual inline std::string GetName() const override { return m_Name; }

			};

		}
	}
}