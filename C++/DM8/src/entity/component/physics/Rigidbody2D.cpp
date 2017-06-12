#include "Rigidbody2D.h"

#include "../../../utils/Time.h"
#include "../../Entity.h"

namespace DM8
{
	namespace entity
	{
		namespace component
		{
			RigidBody2D::RigidBody2D(Entity* entity)
				: Component(entity), PhysicsMaterial(physics::PhysicsMaterial2D::DefaultMaterial)
			{
				ResultantForce = math::Vec2(0, 0);
				Acceleration = math::Vec2(0, 0);
				Mass = 1.0f;
				Velocity = math::Vec2(0, 0);
				GravityScale = 1.0f;
				IsKinematic = false;
				GravityForce = math::Vec2(0.0f, Mass * GravityScale);
				Drag = 0.1f;

				//AddForce(GravityForce, physics::ForceMode::CONTINUOUS);
				Transform = entity->GetComponent<TransformComponent>();
			}

			void RigidBody2D::AddForce(math::Vec2 force)
			{
				AddForce(force, physics::ForceMode::IMMEDIATE);
			}

			void RigidBody2D::AddForce(math::Vec2 force, physics::ForceMode mode)
			{
				ResultantForce += force;
				Acceleration = math::Vec2(ResultantForce.x / Mass, ResultantForce.y / Mass);
				CalculateVelocity();
				if (mode == physics::ForceMode::IMMEDIATE) {
					ResultantForce -= force;
					Acceleration = math::Vec2(ResultantForce.x / Mass, ResultantForce.y / Mass);
				}
			}

			void RigidBody2D::SetPhysicsMaterial(physics::PhysicsMaterial2D material)
			{
				PhysicsMaterial = material;
			}

			void RigidBody2D::Update()
			{
				Transform->Translate(math::Vec3(Velocity.x, Velocity.y, 0.0f));
				CalculateVelocity();
			}

			void RigidBody2D::CalculateVelocity()
			{
				float deltaTime = Time::GetDeltaTime();
				Velocity += math::Vec2(Acceleration.x * deltaTime, Acceleration.y * deltaTime);
				Velocity -= math::Vec2(Drag * Velocity.x, Drag * Velocity.y);
			}

		}
	}
}