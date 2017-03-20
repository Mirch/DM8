#pragma once
#include <string>
#include <GL/glew.h>
#include <glfw/glfw3.h>

#define MAX_KEYS 65535
#define MAX_MOUSE_BUTTONS 120


namespace DM8 {
	namespace graphics {

		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_ID;
			bool m_Closed;

			//keyboard and mouse 
			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_MOUSE_BUTTONS];

			//cursor position
			static double mx, my;
		public:
			Window(const char* title, int width, int height);
			~Window();

			bool Init();

			void Update() const;
			void Clear() const;

			inline GLFWwindow* GetWindow() const { return m_ID; };
			inline bool IsClosed() { return glfwWindowShouldClose(m_ID); };

			static bool IsKeyPressed(unsigned int keycode);
			static bool IsButtonPressed(unsigned int button);

			inline const double& getMouseY() { return my; };
			inline const double& getMouseX() { return mx; };

			friend static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
			friend static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		};

	}
}