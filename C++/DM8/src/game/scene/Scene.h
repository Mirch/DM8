#pragma once

#include <vector>
#include "../../entity/Entity.h"
#include "../../graphics/camera/Camera.h"


namespace DM8
{
	namespace scene
	{
		class Scene
		{
		private:
			std::vector<entity::Entity*> m_Entities;
			graphics::camera::Camera* m_Camera;

			bool DidStart;
		public:
			Scene(const math::Mat4& projectionMatrix);
			~Scene();

			void Add(entity::Entity* entity);

			void Start();
			void Update();
			void Render(graphics::Renderer2D* renderer);

			void CheckCollisions();
			void CheckCollisionsFor(entity::Entity* e1);

			void SetCamera(graphics::camera::Camera* camera);
			inline const graphics::camera::Camera& GetCamera() const { return *m_Camera; }

		};
	}
}