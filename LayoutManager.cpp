#include "LayoutManager.hpp"
#include "Behaviour.hpp"
#include "Container.hpp"

LayoutManager::LayoutManager(
	Behaviour* adding,
	Behaviour* remove
) :
	adding(adding),
	remove(remove)
{	}

LayoutManager::~LayoutManager() {
	if (adding)
		delete adding;
	if (remove)
		delete remove;
}

void LayoutManager::addContainerComponent(Container& container, Component* component) {
	addContainerComponent(&container, component);
}

void LayoutManager::addContainerComponent(Container* container, Component* component) {
	if (component) {
		Component* result = adding->task(container, component);
		if (result) {
			container->addComponent(result);
		}
	}
	//else throw NullPointerException
}

void LayoutManager::removeContainerComponent(Container& container, Component* component) {
	removeContainerComponent(&container, component);
}

void LayoutManager::removeContainerComponent(Container* container, Component* component) {
	if (component) {
		Component* result = remove->task(container, component);
		if (result) {
			container->removeComponent(component);
		}
	}
	//else throw NullPointerException
}