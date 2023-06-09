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

bool Rect::IsOverlappingWith(const Rect& other) const
{
	return (right >= other.left && left <= other.right && top <= other.bottom && bottom >= other.top);
}

Rect Rect::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	//const Vec2 half(halfWidth, halfHeight);
	//return Rect(center - half, center + half);
	Vec2 topleft = Vec2(center.x - halfWidth, center.y - halfHeight);
	Vec2 bottomright = Vec2(center.x + halfWidth, center.y + halfHeight);
	Rect res(topleft.x, topleft.y, bottomright.x, bottomright.y);
	return res;
}

Rect Rect::GetExplanded(float offset) const
{
	return Rect(left - offset, top - offset, right + offset, bottom + offset);
}

