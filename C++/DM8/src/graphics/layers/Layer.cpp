#include "Layer.h"


namespace DM8 {
	namespace graphics {
	
		Layer::Layer(Shader* shader, scene::Scene* scene)
			: m_Shader()
		{
			m_Shader->Enable();
			m_Shader->SetUniformMat4("pr_matrix", const_cast<math::Mat4&>(scene->GetCamera().GetProjectionMatrix()));
			m_Shader->Disable();
		}

	}
}