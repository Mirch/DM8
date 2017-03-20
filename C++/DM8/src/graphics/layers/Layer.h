#pragma once

#include "../Shader.h"
#include "../Renderable2D.h"
#include "../scene/Scene.h"

namespace DM8 {
	namespace graphics {

		class Layer
		{
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
		public:
			Layer(Shader* shader, scene::Scene* scene);
		
			virtual ~Layer()
			{
				for (int i = 0; i < m_Renderables.size(); i++)
				{
					delete m_Renderables[i];
				}
			}
			
			virtual void Render() = 0;
		};

	}
}