#pragma once

#include "Vec2.h"
#include "Vec3.h"

namespace DM8 {
	namespace math
	{

		class Rectangle
		{
		public:
			Vec3* Position;
			Vec2* Size;
		public:
			Rectangle(Vec3* position, Vec2* size);

			bool Intersects(const Rectangle& other) const;

			inline Vec3* GetMinimumBound() const { return Position; }
			inline Vec3* GetMaximumBound() const { return new Vec3(Position->x + Size->x , Position->y + Size->y, Position->z); }

		};

	}
}


