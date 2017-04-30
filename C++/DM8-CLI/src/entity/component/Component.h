#pragma once

#include "../../DMManagedObject.h"

using namespace System;

namespace DM8CLI
{
	namespace entity
	{
		ref class Entity;
		namespace component
		{
			public ref class Component : public DMManagedObject<DM8::entity::component::Component>
			{
			protected:
				Entity^ m_Entity;
			protected:
				Component(DM8::entity::component::Component* instance);
			public:
				Component();

				inline Entity^ GetEntity() { return m_Entity; }
				virtual inline String^ GetName() { return nullptr; }

			};
		}
	}
}