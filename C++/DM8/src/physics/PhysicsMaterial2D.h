#pragma once

namespace DM8 {
	namespace physics
	{
		class PhysicsMaterial2D
		{
		public:
			static PhysicsMaterial2D DefaultMaterial;
			float FrictionCoefficient;
		public:
			PhysicsMaterial2D(float frictionCoefficient);

		};


	}
}