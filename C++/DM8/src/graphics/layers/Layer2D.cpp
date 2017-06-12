#include "Layer2D.h"


namespace DM8 {
	namespace graphics {


		Layer2D::Layer2D(Shader* shader, const math::Mat4 projectionMatrix)
			: Layer(shader, nullptr)
		{
			m_Renderer = new DMRenderer2D();
			m_Scene = new scene::Scene(projectionMatrix);
			m_Shader->Enable();
			m_Shader->SetUniformMat4("pr_matrix", const_cast<math::Mat4&>(projectionMatrix));
			m_Shader->Disable();
		}

		Layer2D::Layer2D(Shader* shader,scene::Scene* scene)
			: Layer(shader, scene)
		{
			m_Scene = scene;
			m_Renderer = new DMRenderer2D();
			m_Shader->Enable();
			m_Shader->SetUniformMat4("pr_matrix", const_cast<math::Mat4&>(scene->GetCamera().GetProjectionMatrix()));
			m_Shader->Disable();
		}

		Layer2D::~Layer2D()
		{
			delete m_Scene;
		}

		void Layer2D::Add(Sprite* sprite)
		{
			//m_Scene->Add(new entity::Entity(sprite));
		}

		void Layer2D::Render()
		{
			m_Shader->Enable();
			m_Scene->Render(m_Renderer);
		}

		void Layer2D::Update()
		{
			m_Scene->Update();
		}


	}
}