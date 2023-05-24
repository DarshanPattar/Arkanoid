#pragma once

#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"

class Brick {
public:
	Brick(const Rect& rect_in, Color c_in);

	void Draw(Graphics& gfx) const;
private:
	Rect rect;
	Color c;
	bool isDestroyed = false;
};