#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel*dt;
}

void Ball::ReBoundY()
{
	vel.y *= -1;
}

void Ball::ReBoundX()
{
	vel.x *= -1;
}

bool Ball::DoWallCollision(const Rect& walls)
{
	bool collided = false;
	if (pos.x <= walls.left) {
		ReBoundX();
		pos.x = walls.left;
		
		collided = true;
	}
	else if (pos.x >= walls.right) {
		ReBoundX();
		pos.x = walls.right;
		
		collided = true;
	}
	if (pos.y >= walls.bottom) {
		ReBoundY();
		pos.y = walls.bottom;
		
		collided = true;
	}
	else if (pos.y <= walls.top) {
		ReBoundY();
		pos.y = walls.top;
		
		collided = true;
	}
	return collided;
}

Rect Ball::GetRect()
{
	Rect res = Rect::FromCenter(pos, radius, radius);
	return res;
}


