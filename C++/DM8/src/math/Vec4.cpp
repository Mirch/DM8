#include "Vec4.h"

namespace DM8 {
	namespace math {

		Vec4::Vec4()
		{
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		Vec4::Vec4(float x, float y, float z, float w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vec4& Vec4::Add(const Vec4 & other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		Vec4& Vec4::Subtract(const Vec4 & other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.y;

			return *this;
		}

		Vec4 & Vec4::Multiply(const Vec4 & other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		Vec4 & Vec4::Divide(const Vec4 & other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w / other.w;

			return *this;
		}


		Vec4 operator+(Vec4 left, const Vec4 & right)
		{
			return left.Add(right);
		}

		Vec4 operator-(Vec4 left, const Vec4 & right)
		{
			return left.Subtract(right);
		}


		bool Vec4::operator==(const Vec4& other) const
		{
			if (x == other.x && y == other.y && z == other.z && w == other.w)
				return true;
			return false;
		}

		bool Vec4::operator!=(const Vec4& other) const
		{
			return !(*this == other);
		}

		Vec4 operator*(Vec4 left, const Vec4 & right)
		{
			return left.Multiply(right);
		}


		Vec4 operator/(Vec4 left, const Vec4 & right)
		{
			return left.Divide(right);
		}


		Vec4& Vec4::operator+=(const Vec4& other)
		{
			return *this + other;
		}

		Vec4& Vec4::operator-=(const Vec4& other)
		{
			return *this - other;
		}

		Vec4& Vec4::operator*=(const Vec4& other)
		{
			return *this * other;
		}

		Vec4& Vec4::operator/=(const Vec4& other)
		{
			return *this / other;
		}

		std::ostream& operator<<(std::ostream& stream, const Vec4& vector)
		{
			stream << vector.x << " " << vector.y << " " << vector.z << " " << vector.w << std::endl;
			return stream;
		}
	}
}


