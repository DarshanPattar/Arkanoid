#pragma once

#include "RectF.h"
#include "Vec2.h"
#include "Colors.h"
#include "Ball.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle {
public:

	Paddle(const Vec2& pos_in, float halfwidth_in, float halfheight_in);
	void Draw(Graphics& gfx) const;

	bool DoBallCollsion(Ball& ball) const;
	void DoWallCollision(const Rect& walls);
	void Update(float dt, const Keyboard& kbd);

	Rect GetRect() const;
	
private:
	float HalfWidth;
	float HalfHeight;
	float paddingLeftRight = 10;

	Color color = Colors::White;
	Vec2 pos;

	float speed = 400.f;
};