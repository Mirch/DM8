#include "Vec2.h"


namespace DM8CLI
{
	namespace math
	{

		Vec2::Vec2()
			: DMManagedObject()
		{
		}

		Vec2::Vec2(DM8::math::Vec2* instance)
			: DMManagedObject(instance)
		{

		}

		Vec2::Vec2(float x, float y)
		{

			m_Instance = new DM8::math::Vec2(x, y);
		}

		Vec2^ Vec2::Add(Vec2^ other)
		{
			return gcnew Vec2(&m_Instance->Add(*other->GetHandle()));
		}

		Vec2^ Vec2::Subtract(Vec2^ other)
		{
			return gcnew Vec2(&m_Instance->Subtract(*other->GetHandle()));
		}

		Vec2^ Vec2::Multiply(Vec2^ other)
		{
			return gcnew Vec2(&m_Instance->Multiply(*other->GetHandle()));
		}

		Vec2^ Vec2::Divide(Vec2^ other)
		{
			return gcnew Vec2(&m_Instance->Divide(*other->GetHandle()));
		}

		Vec2^ Vec2::operator+(Vec2^ left, Vec2^ right)
		{
			return left->Add(right);
		}

		Vec2^ Vec2::operator-(Vec2^ left, Vec2^ right)
		{
			return left->Subtract(right);
		}

		Vec2^ Vec2::operator*(Vec2^ left, Vec2^ right)
		{
			return left->Multiply(right);
		}

		Vec2^ Vec2::operator/(Vec2^ left, Vec2^ right)
		{
			return left->Divide(right);
		}

		bool Vec2::operator==(Vec2^ other)
		{
			return *m_Instance == *other->GetHandle();
		}

		bool Vec2::operator!=(Vec2^ other)
		{
			return *m_Instance != *other->GetHandle();
		}

		Vec2^ Vec2::operator+=(Vec2^ other)
		{
			return Add(other);
		}

		Vec2^ Vec2::operator-=(Vec2^ other)
		{
			return Subtract(other);
		}

		Vec2^ Vec2::operator*=(Vec2^ other)
		{
			return Multiply(other);
		}

		Vec2^ Vec2::operator/=(Vec2^ other)
		{
			return Divide(other);
		}


	}

}
