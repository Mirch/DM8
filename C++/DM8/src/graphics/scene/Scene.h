#pragma once

#include <vector>
#include "../../entity/Entity.h"
#include "../camera/Camera.h"


namespace DM8
{
	namespace graphics
	{
		namespace scene
		{
			class Scene
			{
			private:
				std::vector<entity::Entity*> m_Entities;
				camera::Camera* m_Camera;
			public:
				Scene(const math::Mat4& projectionMatrix);
				~Scene();

				void Add(entity::Entity* entity);

				void Update();
				void Render(graphics::Renderer2D* renderer);

				void SetCamera(camera::Camera* camera);
				inline const camera::Camera& GetCamera() const { return *m_Camera; }
				
			};
		}
	}
}