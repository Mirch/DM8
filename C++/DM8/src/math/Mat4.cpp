#include "Mat4.h"


namespace DM8 {
	namespace math {

		Mat4::Mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}

		Mat4 Mat4::Identity()
		{
			Mat4 result;

			result.elements[0 + 0 * 4] = 1.0f;
			result.elements[1 + 1 * 4] = 1.0f;
			result.elements[2 + 2 * 4] = 1.0f;
			result.elements[3 + 3 * 4] = 1.0f;

			return result;
		}

		Mat4 Mat4::Ortho(float left, float right, float bottom, float top, float near, float far)
		{
			Mat4 result = Identity();

			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			result.elements[0 + 3 * 4] = (left + right) / (left - right);
			result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		Mat4 Mat4::Rotate(float angle)
		{
			Mat4 result = Identity();

			float r = (float)toRadians(angle);
			float cosine = (float)cos(r);
			float sine = (float)sin(r);

			result.elements[0 + 0 * 4] = cosine;
			result.elements[1 + 0 * 4] = sine;
			result.elements[0 + 1 * 4] = -sine;
			result.elements[1 + 1 * 4] = cosine;

			return result;
		}

		Mat4 Mat4::Translate(const Vec3& vector)
		{
			Mat4 result = Identity();

			result.elements[0 + 3 * 4] = vector.x;
			result.elements[1 + 3 * 4] = vector.y;
			result.elements[2 + 3 * 4] = vector.z;

			return result;
		}

		Mat4& Mat4::Multiply(const Mat4& other)
		{
			Mat4 result = Identity();

			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					result.elements[x + y * 4] = sum;
				}
			}
			return result;
		}

		Vec3 Mat4::Multiply(const Vec3& other) const
		{
			return Vec3(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
				);
		}

		Vec4 Mat4::Multiply(const Vec4& other) const
		{
			return Vec4(
				columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w,
				columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w,
				columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w,
				columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w
				);
		}

		Mat4 operator*(Mat4 left, const Mat4& right)
		{
			return left.Multiply(right);
		}

		Mat4& Mat4::operator*=(const Mat4& other)
		{
			return Multiply(other);
		}

		Vec3 operator*(Mat4 left, const Vec3& right)
		{
			return left.Multiply(right);
		}

		Vec4 operator*(Mat4 left, const Vec4& right)
		{
			return left.Multiply(right);
		}
	}
}