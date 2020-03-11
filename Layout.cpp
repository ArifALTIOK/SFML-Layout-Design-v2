#include "Layout.hpp"
#include "LayoutManager.hpp"
Layout::Layout() : manager(0) {}

Layout::Layout(
	LayoutManager* manager
) :
	Layout()
{
	setLayoutManager(manager);
}

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