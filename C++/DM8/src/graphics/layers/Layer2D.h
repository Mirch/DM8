#pragma once

#include "Layer.h"
#include "../DMRenderer2D.h"

namespace DM8 {
	namespace graphics {

		class Layer2D : public Layer 
		{
		private:
			scene::Scene* m_Scene;
		public:
			Layer2D(Shader* shader, const math::Mat4 projectionMatrix);
			Layer2D(Shader* shader, scene::Scene* scene);
			~Layer2D();

			void Add(Sprite* sprite);

			void Render() override;
			void Update() override;

		};

	}
}