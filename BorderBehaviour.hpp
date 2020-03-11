#pragma once
#include "DecaratorBehaviour.hpp"
#include "Rect.hpp"
class BorderBehaviour : public DecaratorBehaviour {
protected:
	std::vector<FloatRect> sBound;
public:
	using DecaratorBehaviour::DecaratorBehaviour;
};