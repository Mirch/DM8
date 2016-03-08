#include "Vec3.h"

namespace DM8 {
	namespace math {

		Vec3::Vec3()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		Vec3::Vec3(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vec3& Vec3::Add(const Vec3 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		Vec3& Vec3::Subtract(const Vec3 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		Vec3 & Vec3::Multiply(const Vec3 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		Vec3 & Vec3::Divide(const Vec3 & other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}


		Vec3 operator+(Vec3 left, const Vec3 & right)
		{
			return left.Add(right);
		}

		Vec3 operator-(Vec3 left, const Vec3 & right)
		{
			return left.Subtract(right);
		}


		bool Vec3::operator==(const Vec3& other) const
		{
			if (x == other.x && y == other.y && z == other.z)
				return true;
			return false;
		}

		bool Vec3::operator!=(const Vec3& other) const
		{
			return !(*this == other);
		}

		Vec3 operator*(Vec3 left, const Vec3 & right)
		{
			return left.Multiply(right);
		}


		Vec3 operator/(Vec3 left, const Vec3 & right)
		{
			return left.Divide(right);
		}


		Vec3& Vec3::operator+=(const Vec3& other)
		{
			return *this + other;
		}

		Vec3& Vec3::operator-=(const Vec3& other)
		{
			return *this - other;
		}

		Vec3& Vec3::operator*=(const Vec3& other)
		{
			return *this * other;
		}

		Vec3& Vec3::operator/=(const Vec3& other)
		{
			return *this / other;
		}

		std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
		{
			stream << vector.x << " " << vector.y << " " << vector.z <<std::endl;
			return stream;
		}
	}
}


