#pragma once
#include "Behaviour.hpp"
class TopToBottomAdding : public AddingBehaviour{
public:
	Component* task(const Container* container, Component* component);
};

