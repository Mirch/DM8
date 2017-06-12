#pragma once

namespace DM8
{
	class Time
	{
	private:
		static float m_Time;
		static float m_DeltaTime;
		static float m_LastTime;
	private:
		Time();
	public:
		static float GetTime();
		static float GetDeltaTime();

		static void RestartDeltaTimeCounter();

		static void Update();
	};
}