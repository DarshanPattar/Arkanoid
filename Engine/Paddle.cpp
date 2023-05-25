#include "Paddle.h"

Paddle::Paddle(const Vec2& pos_in, float halfwidth_in, float halfheight_in)
{
	pos = pos_in;
	HalfWidth = halfwidth_in;
	HalfHeight = halfheight_in;
}

void Paddle::Draw(Graphics& gfx) const
{
	Rect res = GetRect();
	Rect innerRect = res;
	innerRect.left = res.left + paddingLeftRight;
	innerRect.right = res.right - paddingLeftRight;

	gfx.DrawRect(res, color);
	gfx.DrawRect(innerRect, Colors::Red);
}

bool Paddle::DoBallCollsion(Ball& ball) const
{
	Rect res = GetRect();
	if (res.IsOverlappingWith(ball.GetRect())) {
		if (ball.GetVelocity().y > 0) {
			ball.ReBoundY();
			return true;
		}
	}
	return false;
}

void Paddle::DoWallCollision(const Rect& walls)
{
	Rect res = GetRect();
	if (res.left < walls.left) {
		pos.x += (walls.left - res.left);
	}
	if (res.right > walls.right) {
		pos.x -= (res.right - walls.right);
	}
}

void Paddle::Update(float dt, const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		pos.x -= speed * dt;
	}
	if (kbd.KeyIsPressed(VK_RIGHT) ){
		pos.x += speed * dt;
	}
}

Rect Paddle::GetRect() const
{
	Rect res = Rect::FromCenter(pos, HalfWidth, HalfHeight);
	return res;
}
