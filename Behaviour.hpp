#pragma once
class Component;
class Container;
__interface Behaviour {
	Component* task(const Container* container, Component* component);
};

struct AddingBehaviour : Behaviour {	};

struct RemoveBehaviour : Behaviour {	};

struct DefaultBehaviour : Behaviour {
	Component* task(const Container* container, Component* component) {
		return component;
	}
};

class DecaratorBehaviour : public Behaviour {
protected:
	Behaviour* behaviour;
public:
	DecaratorBehaviour(
		Behaviour* behaviour
	) :
		behaviour(behaviour)
	{	}
};