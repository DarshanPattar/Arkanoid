#pragma once

#include "Vec2.h"

class Rect {
public:
	Rect() = default;
	Rect( float left_in, float top_in, float right_in, float bottom_in);
	Rect(const Vec2& topleft, const Vec2& bottomright);
	Rect(const Vec2& topleft, float bottom, float right);

private:
	float top;
	float left;
	float bottom;
	float right;
};