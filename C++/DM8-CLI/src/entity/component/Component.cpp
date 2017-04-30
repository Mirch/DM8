#pragma once

#include "Component.h"

namespace DM8CLI
{
	namespace entity
	{
		namespace component
		{
			Component::Component()
				: DMManagedObject()
			{
			}

			Component::Component(DM8::entity::component::Component* instance)
				: DMManagedObject(instance)
			{
			}


		}
	}
}