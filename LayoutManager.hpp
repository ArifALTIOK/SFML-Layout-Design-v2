#pragma once
class Behaviour;
class Container;
class Component;

class LayoutManager {
protected:
	Behaviour* adding;
	Behaviour* remove;
public:
	LayoutManager(
		Behaviour* adding,
		Behaviour* remove
	);

	~LayoutManager();


	void addContainerComponent(Container& container, Component* component);
	void addContainerComponent(Container* container, Component* component);

	void removeContainerComponent(Container& container, Component* component);
	void removeContainerComponent(Container* container, Component* component);
};