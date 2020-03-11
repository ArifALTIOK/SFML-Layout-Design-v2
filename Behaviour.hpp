#pragma once

#ifndef min 
#define min(x,y) x<y?x:y;
#endif

#ifndef max
#define max(x,y) x<y?x:y;
#endif

#include <vector>
class Component;
class Container;
__interface IBehaviour
{
	Component* task(const Container* container, Component* component);
};

class Behaviour : public IBehaviour{	};

class AddingBehaviour : public Behaviour {	};

class RemoveBehaviour : public Behaviour {	};

class DefaultBehaviour : public Behaviour {
public:
	Component* task(const Container* container, Component* component) {
		return component;
	}
};

