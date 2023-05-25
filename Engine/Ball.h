#pragma once

#include "Vec2.h"
#include "Graphics.h"


class Ball {
public:
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	void Draw(Graphics& gfx) const;
	void Update(float dt);


	void ReBoundX();
	void ReBoundY();
	bool DoWallCollision(const Rect& walls);

	Rect GetRect();
	inline Vec2 GetVelocity() { return vel; }
	inline Vec2 GetPosition() { return pos; }

private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;
};