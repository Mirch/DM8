#include "Time.h"

#include "GLFW\glfw3.h"

namespace DM8
{
	 float Time::m_Time;
	 float Time::m_DeltaTime;
	 float Time::m_LastTime;

	Time::Time()
	{
	}

	float Time::GetTime()
	{
		return glfwGetTime();
	}

	float Time::GetDeltaTime()
	{
		return m_DeltaTime;
	}

	void Time::RestartDeltaTimeCounter()
	{
		m_DeltaTime = 0;
	}

	void Time::Update()
	{
		m_DeltaTime = glfwGetTime() - m_LastTime;
		m_LastTime = glfwGetTime();
	}

}