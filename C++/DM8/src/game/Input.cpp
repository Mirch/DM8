#include "Input.h"


namespace DM8 {

	bool Input::m_Keys[MAX_KEYS];
	bool Input::m_MouseButtons[MAX_MOUSE_BUTTONS];
	double Input::mx;
	double Input::my;

	bool Input::IsKeyPressed(unsigned int keycode)
	{
		if (keycode >= MAX_KEYS) return false;

		return m_Keys[keycode];
	}

	bool Input::IsButtonPressed(unsigned int button)
	{
		if (button >= MAX_MOUSE_BUTTONS) return false;

		return m_MouseButtons[button];
	}

	void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		m_Keys[key] = (action != GLFW_RELEASE);
	}

	void Input::CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
	{
		mx = xpos;
		my = ypos;
	}

	void Input::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		m_MouseButtons[button] = (action != GLFW_RELEASE);
	}

}