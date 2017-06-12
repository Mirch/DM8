#include "EntityBehaviour.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			EntityBehaviour::EntityBehaviour(std::string name, Entity* entity)
				: m_Name(name), Component(entity)
			{
			}

			void EntityBehaviour::Start()
			{

			}

			void EntityBehaviour::Update()
			{

			}


		}
	}
}
