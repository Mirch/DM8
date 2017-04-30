#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace DM8 {
	namespace math {
		inline float toRadians(float angle)
		{
			return angle * M_PI / 180.0f;
		}
	}
}