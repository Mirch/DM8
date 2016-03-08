#include "Vec2.h"

namespace DM8 {
	namespace math {

		Vec2::Vec2()
		{
			x = 0;
			y = 0;
		}

		Vec2::Vec2(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		Vec2& Vec2::Add(const Vec2 & other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		Vec2& Vec2::Subtract(const Vec2 & other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vec2 & Vec2::Multiply(const Vec2 & other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		Vec2 & Vec2::Divide(const Vec2 & other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}


		Vec2 operator+(Vec2 left, const Vec2 & right)
		{
			return left.Add(right);
		}

		Vec2 operator-(Vec2 left, const Vec2 & right)
		{
			return left.Subtract(right);
		}


		bool Vec2::operator==(const Vec2& other) const
		{
			if (x == other.x && y == other.y)
				return true;
			return false;
		}

		bool Vec2::operator!=(const Vec2& other) const
		{
			return !(*this == other);
		}

		Vec2 operator*(Vec2 left, const Vec2 & right)
		{
			return left.Multiply(right);
		}


		Vec2 operator/(Vec2 left, const Vec2 & right)
		{
			return left.Divide(right);
		}


		Vec2& Vec2::operator+=(const Vec2& other)
		{
			return *this + other;
		}

		Vec2& Vec2::operator-=(const Vec2& other)
		{
			return *this - other;
		}

		Vec2& Vec2::operator*=(const Vec2& other)
		{
			return *this * other;
		}

		Vec2& Vec2::operator/=(const Vec2& other)
		{
			return *this / other;
		}

		std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
		{
			stream << vector.x << " " << vector.y << std::endl;
			return stream;
		}
	}
}


