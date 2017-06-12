#include "PhysicsMaterial2D.h"


namespace DM8 {
	namespace physics
	{
		PhysicsMaterial2D PhysicsMaterial2D::DefaultMaterial(0.1f);

		PhysicsMaterial2D::PhysicsMaterial2D(float frictionCoefficient)
			: FrictionCoefficient(frictionCoefficient)
		{
		}


	}
}