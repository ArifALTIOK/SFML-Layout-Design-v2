#include "Layout.hpp"
#include "LayoutManager.hpp"

Layout::Layout(
	Vector2f size,
	LayoutManager* manager
) : 
	manager(NULL)
{
	preferredSize = size;
	setLayoutManager(manager);
}

Layout::Layout(
	float x,
	float y,
	LayoutManager* manager
) : 
	Layout(Vector2f(x,y),manager)
{	}

void Layout::setLayoutManager(LayoutManager* manager) {
	if (this->manager)
		delete this->manager;
	this->manager = manager;
}

void Layout::addLayoutComponent(Component* component) {
	manager->addContainerComponent(this, component);
}

void Layout::removeLayoutComponent(Component* component) {
	manager->removeContainerComponent(this, component);
}

