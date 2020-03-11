#pragma once
#include "BorderBehaviour.hpp"
class VerticalBorder : public BorderBehaviour {
public:
	using BorderBehaviour::BorderBehaviour;
	Component* task(const Container* container, Component* component);
};