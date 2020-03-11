#include "IGaps.hpp"

Vector2f IGaps::getHorizontalGaps()const {
	return Vector2f(getLeftTopGaps().x, getRightBottomGaps().x);
}

Vector2f IGaps::getVerticalGaps()const {
	return Vector2f(getLeftTopGaps().y, getRightBottomGaps().y);
}