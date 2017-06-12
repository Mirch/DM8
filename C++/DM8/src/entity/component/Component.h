#pragma once

#include <string>

namespace DM8
{
	namespace entity
	{
		class Entity;
	}
}


namespace DM8
{
	namespace entity
	{
		namespace component
		{
			class Component
			{
			public:
				Entity* EntityObject;
			public:
				Component(Entity* entity);

				inline Entity* GetEntity() const { return EntityObject; }
				virtual inline std::string GetName() const { return nullptr; }

				virtual void Update();

			};
		}
	}
}