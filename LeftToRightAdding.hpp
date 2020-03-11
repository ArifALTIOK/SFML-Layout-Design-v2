#pragma once
#include "Behaviour.hpp"
class LeftToRightAdding : public AddingBehaviour {
public:
	Component* task(const Container* container, Component* component);
};