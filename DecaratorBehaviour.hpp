#pragma once
#include "Behaviour.hpp"
class DecaratorBehaviour : public Behaviour {
protected:

	Behaviour* behaviour;
public:
	DecaratorBehaviour(Behaviour* behaviour);
};