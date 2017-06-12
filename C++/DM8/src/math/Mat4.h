#pragma once

#include "../utils/maths_func.h"
#include "Vec3.h"
#include "Vec4.h"

#define SIZE 4 * 4


namespace DM8 {
	namespace math {

		class Mat4
		{
		public:
			union
			{
				float elements[SIZE];
				Vec4 columns[4];
			};
		public:
			Mat4();

			static Mat4 Identity();

			static Mat4 Ortho(float left, float right, float bottom, float top, float near, float far);
			static Mat4 Rotate(float angle);
			static Mat4 RotateAround(float angle, Vec3 point);
			static Mat4 Translate(const Vec3& vector);

			Mat4& Multiply(const Mat4& other);

			Vec3 Multiply(const Vec3& other) const;
			Vec4 Multiply(const Vec4& other) const;

			friend Mat4 operator*(Mat4 left, const Mat4& right);
			Mat4& operator*=(const Mat4& other);

			friend Vec3 operator*(Mat4 left, const Vec3& right);
			friend Vec4 operator*(Mat4 left, const Vec4& right);
		};

	}
}