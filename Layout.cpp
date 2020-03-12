#include "Layout.hpp"
#include "LayoutManager.hpp"
Layout::Layout() : manager(0) {}

Layout::Layout(
	LayoutManager* manager,
	float x,
	float y
) :
	Layout()
{
	preferredSize = Vector2f(x, y);
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

void Layout::rotateAllComponent(float angle)
{
	size_t nComp = getComponentCount();
	for (size_t i = 0; i < nComp; i++)
		getComponent(i)->rotate(angle);
}
