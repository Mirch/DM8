#pragma once

#include <iostream>

namespace DM8 {
	namespace math {

		class Vec3
		{
		public:
			float x, y, z;
		public:
			Vec3();
			Vec3(float x, float y, float z);

			Vec3& Add(const Vec3& other);
			Vec3& Subtract(const Vec3& other);
			Vec3& Multiply(const Vec3& other);
			Vec3& Divide(const Vec3& other);

			friend Vec3 operator+(Vec3 left, const Vec3& right);
			friend Vec3 operator-(Vec3 left, const Vec3& right);
			friend Vec3 operator*(Vec3 left, const Vec3& right);
			friend Vec3 operator/(Vec3 left, const Vec3& right);

			bool operator==(const Vec3& other) const;
			bool operator!=(const Vec3& other) const;

			Vec3& operator+=(const Vec3& other);
			Vec3& operator-=(const Vec3& other);
			Vec3& operator*=(const Vec3& other);
			Vec3& operator/=(const Vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);



		};

	}
}


