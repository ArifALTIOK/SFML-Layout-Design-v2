#pragma once
#include "Vector2.hpp"
class IGaps {
public:
	virtual Vector2f getLeftTopGaps()const = 0;
	virtual Vector2f getRightBottomGaps()const = 0;
	Vector2f getHorizontalGaps()const;
	Vector2f getVerticalGaps()const;
};

class NoGaps : public IGaps {
public:
	Vector2f getLeftTopGaps()const {
		return Vector2f(0, 0);
	}

	Vector2f getRightBottomGaps()const {
		return Vector2f(0, 0);
	}
};

class Gaps : public IGaps {
public:
	float left, top, right, bottom;
	Gaps(
		float left = 0,
		float top = 0,
		float right = 0,
		float bottom = 0
	) :
		left(left),
		top(top),
		right(right),
		bottom(bottom)
	{	}

	Vector2f getHorizontalGaps()const {
		return Vector2f(left, right);
	}

	Vector2f getVerticalGaps()const {
		return Vector2f(top, bottom);
	}
};
