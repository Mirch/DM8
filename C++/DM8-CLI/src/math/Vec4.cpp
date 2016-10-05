#include "Vec4.h"

namespace DM8CLI
{
	namespace math
	{

		Vec4::Vec4()
			: DMManagedObject()
		{
		}

		Vec4::Vec4(DM8::math::Vec4* instance)
			: DMManagedObject(instance)
		{

		}

		Vec4::Vec4(float x, float y, float z, float w)
		{

			m_Instance = new DM8::math::Vec4(x, y, z, w);
		}

		Vec4^ Vec4::Add(Vec4^ other)
		{
			return gcnew Vec4(&m_Instance->Add(*other->GetHandle()));
		}

		Vec4^ Vec4::Subtract(Vec4^ other)
		{
			return gcnew Vec4(&m_Instance->Subtract(*other->GetHandle()));
		}

		Vec4^ Vec4::Multiply(Vec4^ other)
		{
			return gcnew Vec4(&m_Instance->Multiply(*other->GetHandle()));
		}

		Vec4^ Vec4::Divide(Vec4^ other)
		{
			return gcnew Vec4(&m_Instance->Divide(*other->GetHandle()));
		}

		Vec4^ Vec4::operator+(Vec4^ left, Vec4^ right)
		{
			return left->Add(right);
		}

		Vec4^ Vec4::operator-(Vec4^ left, Vec4^ right)
		{
			return left->Subtract(right);
		}

		Vec4^ Vec4::operator*(Vec4^ left, Vec4^ right)
		{
			return left->Multiply(right);
		}


		Vec4^ Vec4::operator/(Vec4^ left, Vec4^ right)
		{
			return left->Divide(right);
		}

		bool Vec4::operator==(Vec4^ other)
		{
			return *m_Instance == *other->GetHandle();
		}

		bool Vec4::operator!=(Vec4^ other)
		{
			return *m_Instance != *other->GetHandle();
		}

		Vec4^ Vec4::operator+=(Vec4^ other)
		{
			return Add(other);
		}

		Vec4^ Vec4::operator-=(Vec4^ other)
		{
			return Subtract(other);
		}

		Vec4^ Vec4::operator*=(Vec4^ other)
		{
			return Multiply(other);
		}

		Vec4^ Vec4::operator/=(Vec4^ other)
		{
			return Divide(other);
		}


	}
}