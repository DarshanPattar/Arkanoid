#include "Brick.h"



Brick::Brick(const Rect& rect_in, Color c_in)
	:
	rect(rect_in),
	c(c_in)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!isDestroyed) {
		gfx.DrawRect(rect.GetExplanded(padding), c);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	Rect ballrect = ball.GetRect();
	if (!isDestroyed && rect.IsOverlappingWith(ballrect)) {

		Vec2 ballpos = ball.GetPosition();

		if (ballpos.x > rect.left && ballpos.x < rect.right) {
			ball.ReBoundY();
		}
		else {
			ball.ReBoundX();
		}
		isDestroyed = true;
		return true;
	}
	return false;
}
