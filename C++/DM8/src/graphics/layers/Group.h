#pragma once

#include <vector>
#include "../Renderable2D.h"

namespace DM8 {
	namespace graphics {

		class Group
		{
		private:
			std::vector<Renderable2D*> m_Renderables;
			math::Mat4 m_TransformationMatrix;
		public:
			Group(const math::Mat4& transoform);
			~Group();

			void Push(Renderable2D* renderable);
			void Submit(Renderer2D* renderer);
		};


	}

}