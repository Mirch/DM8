#pragma once

#include <vector>
#include "../math/Mat4.h"


namespace DM8 {
	namespace graphics {

		class Renderable2D;

		class Renderer2D
		{
		protected:
			std::vector<math::Mat4> m_TransformationStack;
			math::Mat4* m_TransfBack;
		protected:
			Renderer2D()
			{
				m_TransformationStack.push_back(math::Mat4::Identity());
				m_TransfBack = &m_TransformationStack.back();
			}
		public:
			~Renderer2D() {}

		public:

			void Push(math::Mat4 matrix, bool over = false)
			{
				if (over)
					m_TransformationStack.push_back(matrix);
				else
					m_TransformationStack.push_back(m_TransformationStack.back().Multiply(matrix));

			}

			void Pop()
			{
				if (m_TransformationStack.size() > 1)
					m_TransformationStack.pop_back();
			}

			virtual void Begin() {}
			virtual void End() {}

			virtual void Submit(const Renderable2D* renderable) {}

			virtual void Flush() {}
		};


	}
}