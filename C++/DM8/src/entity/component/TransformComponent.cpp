#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "physics/CollisionBox.h"
#include "../Entity.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			TransformComponent::TransformComponent(const math::Mat4& transform, Entity* entity)
				: Component(entity)
			{
				m_Transform = transform;
				m_Position = entity->GetComponent<SpriteComponent>()->m_Sprite->GetPosition();
				m_Size = entity->GetComponent<SpriteComponent>()->m_Sprite->GetSize();
				m_Angle = 0;
			}

			void TransformComponent::Translate(const math::Vec3& vector)
			{
				CollisionBox* cb = EntityObject->GetComponent<CollisionBox>();

				math::Vec3 tempVec = math::Vec3(-1.3 * vector.x, -1.3* vector.y, -1.3 * vector.z);

				m_Position += vector;
				m_Transform = m_Transform * math::Mat4::Translate(vector);

				if (cb) {
					cb->CheckCollisions();
					if (cb->IsColliding()) {
						m_Position += tempVec;
						m_Transform = m_Transform * math::Mat4::Translate(tempVec);
					}
				}
			}

			void TransformComponent::Rotate(float angle)
			{
				math::Vec2 size = EntityObject->GetComponent<SpriteComponent>()->m_Sprite->GetSize();

				math::Vec3 tempPos = m_Position;

				Translate(math::Vec3(-m_Position.x - size.x / 2, -m_Position.y - size.y / 2, 0.0f));
				m_Transform = m_Transform * math::Mat4::Rotate(angle);
				Translate(math::Vec3(tempPos.x + size.x / 2, tempPos.y + size.y / 2, 0.0f));
			}

		}
	}
}