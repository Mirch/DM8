#include "Window.h"

namespace DM8CLI {
	namespace graphics {
		using namespace System::Runtime::InteropServices;

		Window::Window(DM8::graphics::Window* instance)
			: DMManagedObject(instance)
		{

		}

		Window::Window(String^ name, int width, int height)
		{
			const char* nameString = string_to_char_array(name);
			m_Instance = new DM8::graphics::Window(nameString, width, height);
		}

		bool Window::Init()
		{
			return m_Instance->Init();
		}

		void Window::Update()
		{
			m_Instance->Update();
		}

		void Window::Clear()
		{
			m_Instance->Clear();
		}

		bool Window::IsKeyPressed(unsigned int keycode)
		{
			return DM8::graphics::Window::IsKeyPressed(keycode);
		}

		bool Window::IsButtonPressed(unsigned int button)
		{
			return DM8::graphics::Window::IsButtonPressed(button);
		}


	}
}