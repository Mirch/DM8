#pragma once

#include "../Component.h"
#include "../TransformComponent.h"
#include "../../../math/Vec2.h"
#include "../../../physics/PhysicsMaterial2D.h"
#include "../../../physics/ForceMode.h"
namespace DM8
{
	namespace entity
	{
		namespace component
		{

			class RigidBody2D : public Component
			{
			private:
				math::Vec2 ResultantForce;
				math::Vec2 GravityForce;
				math::Vec2 Acceleration;
				TransformComponent* Transform;
			public:
				float Mass;
				math::Vec2 Velocity;
				bool IsKinematic;
				float GravityScale;
				float Drag;
				physics::PhysicsMaterial2D PhysicsMaterial;
			public:
				RigidBody2D(Entity* entity);

				void AddForce(math::Vec2 force);
				void AddForce(math::Vec2 force, physics::ForceMode mode);
				void SetPhysicsMaterial(physics::PhysicsMaterial2D material);

				void Update() override;

				static std::string GetStaticName()
				{
					return "RigidBody2D";
				}

				virtual inline std::string GetName() const override { return GetStaticName(); }
			private:
				void CalculateVelocity();

			};

		}
	}
}