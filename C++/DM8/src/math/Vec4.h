#pragma once

#include <iostream>

namespace DM8 {
	namespace math {

		class Vec4
		{
		public:
			float x, y, z, w;
		public:
			Vec4();
			Vec4(float x, float y, float z, float w);

			Vec4& Add(const Vec4& other);
			Vec4& Subtract(const Vec4& other);
			Vec4& Multiply(const Vec4& other);
			Vec4& Divide(const Vec4& other);

			friend Vec4 operator+(Vec4 left, const Vec4& right);
			friend Vec4 operator-(Vec4 left, const Vec4& right);
			friend Vec4 operator*(Vec4 left, const Vec4& right);
			friend Vec4 operator/(Vec4 left, const Vec4& right);

			bool operator==(const Vec4& other) const;
			bool operator!=(const Vec4& other) const;

			Vec4& operator+=(const Vec4& other);
			Vec4& operator-=(const Vec4& other);
			Vec4& operator*=(const Vec4& other);
			Vec4& operator/=(const Vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);



		};

	}
}


