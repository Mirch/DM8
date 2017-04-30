#pragma once

#include "../Renderer2D.h"
#include "../Shader.h"
#include "../Renderable2D.h"

namespace DM8 {
	namespace graphics {

		class Layer
		{
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderables;
			Shader* m_Shader;
			math::Mat4 m_ProjectionMatrix;
		public:
			Layer(Renderer2D* renderer, Shader* shader,const math::Mat4& projectionMatrix);
		
			virtual ~Layer()
			{
				for (int i = 0; i < m_Renderables.size(); i++)
				{
					delete m_Renderables[i];
				}
			}
			
			void Push(Renderable2D* renderable);
			void Render();
		};

	}
}