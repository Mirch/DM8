#pragma once

#include <GLFW\glfw3.h>

#define MAX_KEYS 65535
#define MAX_MOUSE_BUTTONS 120


namespace DM8 {

	class Input
	{
	private:
		static bool m_Keys[MAX_KEYS];
		static bool m_MouseButtons[MAX_MOUSE_BUTTONS];

		static double mx, my;
	public:
		static bool IsKeyPressed(unsigned int keycode);
		static bool IsButtonPressed(unsigned int button);

		inline const double& getMouseY() { return my; };
		inline const double& getMouseX() { return mx; };

		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	};

}
