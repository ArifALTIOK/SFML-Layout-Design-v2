#pragma once
#include "BorderBehaviour.hpp"
class HorizontalBorder : public BorderBehaviour {
public:
	using BorderBehaviour::BorderBehaviour;
	Component* task(const Container* container, Component* component);
};
