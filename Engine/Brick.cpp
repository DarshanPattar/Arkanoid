#include "Brick.h"



Brick::Brick(const Rect& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if(!isDestroyed)
		gfx.DrawRect(rect, c);
}

bool Brick::DoBallCollision(Ball& ball)
{
	Rect ballrect = ball.GetRect();
	if (!isDestroyed && rect.IsOverlappingWith(ballrect)) {
		isDestroyed = true;
		ball.ReBoundY();
		return true;
	}
	return false;
}
