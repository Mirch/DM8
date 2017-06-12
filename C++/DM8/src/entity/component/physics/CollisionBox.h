#pragma once

#include "../Component.h"
#include "../../../math/Rectangle.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			class CollisionBox : public Component
			{
			private:
				bool m_IsColliding;
			public:
				math::Rectangle* Rectangle;
			public:
				CollisionBox(Entity* entity);

				bool Intersects(const CollisionBox& other);

				inline void SetColliding(bool value) { m_IsColliding = value; }
				inline bool IsColliding() { return m_IsColliding; }
				void CheckCollisions();

				static std::string GetStaticName()
				{
					return "CollisionBox";
				}

				virtual inline std::string GetName() const override { return GetStaticName(); }
			};


		}
	}
}