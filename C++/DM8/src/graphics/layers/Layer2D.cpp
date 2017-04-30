#include "Layer2D.h"


namespace DM8 {
	namespace graphics {


		Layer2D::Layer2D(Shader* shader, const math::Mat4 projectionMatrix)
			: Layer(shader, m_Scene)
		{
			m_Scene = new scene::Scene(projectionMatrix);
			m_Renderer = new DMRenderer2D();
		}

		void Layer2D::Add(Sprite* sprite)
		{
			m_Scene->Add(new entity::Entity(sprite));
		}

		void Layer2D::Render()
		{
			m_Scene->Render(m_Renderer);
		}


	}
}