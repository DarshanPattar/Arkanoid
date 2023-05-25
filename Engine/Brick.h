#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
public:
	Brick() = default;
	Brick(const Rect& rect_in, Color c_in);

	void Draw(Graphics& gfx) const;

	bool DoBallCollision(Ball& ball);
private:
	Rect rect;
	Color c;
	bool isDestroyed = false;
};