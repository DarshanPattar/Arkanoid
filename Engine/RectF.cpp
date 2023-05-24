#include "RectF.h"



Rect::Rect(float left_in, float top_in, float right_in, float bottom_in)
{
	top = top_in;
	bottom = bottom_in;
	left = left_in;
	right = right_in;
}

Rect::Rect(const Vec2& topleft, const Vec2& bottomright)
{
	Rect(topleft.x, topleft.y, bottomright.x, bottomright.y);
}

Rect::Rect(const Vec2& topleft, float bottom, float right)
{
	Rect(topleft, Vec2(right, bottom));
}
