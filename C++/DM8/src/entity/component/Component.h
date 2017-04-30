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
			protected:
				Entity* m_Entity;
			public:
				inline Entity* GetEntity() const { return m_Entity; }
				virtual inline std::string GetName() const { return nullptr; }
			};
		}
	}
}