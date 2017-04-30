#pragma once

#include <iostream>

namespace DM8 {
	namespace math {
	
		class Vec2 
		{
		public:
			float x, y;
		public:
			Vec2();
			Vec2(float x, float y);
		
			Vec2& Add(const Vec2& other);
			Vec2& Subtract(const Vec2& other);
			Vec2& Multiply(const Vec2& other);
			Vec2& Divide(const Vec2& other);

			friend Vec2 operator+(Vec2 left, const Vec2& right);
			friend Vec2 operator-(Vec2 left, const Vec2& right);
			friend Vec2 operator*(Vec2 left, const Vec2& right);
			friend Vec2 operator/(Vec2 left, const Vec2& right);

			bool operator==(const Vec2& other) const;
			bool operator!=(const Vec2& other) const;

			Vec2& operator+=(const Vec2& other);
			Vec2& operator-=(const Vec2& other);
			Vec2& operator*=(const Vec2& other);
			Vec2& operator/=(const Vec2& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);



		};

	}

}