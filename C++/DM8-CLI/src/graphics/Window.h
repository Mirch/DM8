#pragma once

#include "../DMManagedObject.h"

namespace DM8CLI {
	namespace graphics {

		using namespace System;

		public ref class Window : public DMManagedObject<DM8::graphics::Window>
		{
		private:
			Window(DM8::graphics::Window* instance);
		public:
			Window(String^ name, int width, int height);

			bool Init();

			void Update();
			void Clear();

			inline bool IsClosed() { return m_Instance->IsClosed(); };

			static bool IsKeyPressed(unsigned int keycode);
			static bool IsButtonPressed(unsigned int button);

			inline double GetMouseX() { return m_Instance->getMouseX(); };
			inline double GetMouseY() { return m_Instance->getMouseY(); };

		};

	

	}
}