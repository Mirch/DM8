#include "Window.h"
#include <iostream>

#include "../game/Input.h"

namespace DM8 {
	namespace graphics {

		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_MOUSE_BUTTONS];
		double Window::mx;
		double Window::my;
	
		Window::Window(const char* title, int width, int height)
			: m_Title(title), m_Width(width), m_Height(height)
		{
			m_Closed = false;
			if (!Init())
				return;

		}

		Window::~Window()
		{
			m_Closed = true;
			//glfwDestroyWindow(m_ID);
			glfwTerminate();
		}

		bool Window::Init()
		{
			if (glfwInit() == GL_FALSE)
			{
				std::cout << "Failed to initialise GLFW!" << std::endl;
				return false;
			}


			//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			m_ID = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_ID)
			{
				std::cout << "Failed to create the window!" << std::endl;
				return false;
			}
			glfwSetWindowUserPointer(m_ID, this);
			glfwMakeContextCurrent(m_ID);

			glfwSetKeyCallback(m_ID, Input::KeyCallback);
			glfwSetCursorPosCallback(m_ID, Input::CursorPositionCallback);
			glfwSetMouseButtonCallback(m_ID, Input::MouseButtonCallback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialise GLEW!" << std::endl;
			}

			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		}

		void Window::Update() const
		{
			GLsizei error = glGetError();
			if (error != GL_NO_ERROR) {
				std::cout << error << std::endl;
			}
			glfwPollEvents();
			glfwSwapBuffers(m_ID);
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}


		bool Window::IsKeyPressed(unsigned int keycode)
		{
			return m_Keys[keycode];
		}

		bool Window::IsButtonPressed(unsigned int button)
		{
			return m_MouseButtons[button];
		}

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = (action != GLFW_RELEASE);
			
		}

		void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
			
		}

		void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = (action != GLFW_RELEASE);
		}


	}
}