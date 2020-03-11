#pragma once
#include "Rect.hpp"
class IBounds {
public:
	virtual FloatRect getLocalBounds()const = 0;
	virtual FloatRect getGlobalBounds()const = 0;
};