#include "Rectangle.h"

namespace DM8 {
	namespace math
	{


		Rectangle::Rectangle(Vec3* position, Vec2* size)
			: Position(position), Size(size)
		{
		}

		bool Rectangle::Intersects(const Rectangle& other) const
		{
			Vec3* minBound1 = GetMinimumBound();
			Vec3* maxBound1 = GetMaximumBound();
			Vec3* minBound2 = other.GetMinimumBound();
			Vec3* maxBound2 = other.GetMaximumBound();

			bool collisionX = maxBound1->x >= minBound2->x && maxBound2->x >= minBound1->x;
			bool collisionY = maxBound1->y >= minBound2->y && maxBound2->y >= minBound1->y;

			return collisionX && collisionY;
		}



	}
}