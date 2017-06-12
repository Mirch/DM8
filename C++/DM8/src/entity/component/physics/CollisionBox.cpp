#include "CollisionBox.h"
#include "../../Entity.h"
#include "../../../game/scene/Scene.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			CollisionBox::CollisionBox(Entity* entity)
				: Component(entity)
			{
				math::Vec3* pos = &(EntityObject->GetComponent<TransformComponent>()->m_Position);
				math::Vec2* size = &(EntityObject->GetComponent<TransformComponent>()->m_Size);
				Rectangle = new math::Rectangle(pos, size);
			}

			bool CollisionBox::Intersects(const CollisionBox& other)
			{
				return Rectangle->Intersects(*other.Rectangle);
			}

			void CollisionBox::CheckCollisions()
			{
				EntityObject->Scene->CheckCollisionsFor(EntityObject);
			}


		}
	}
}