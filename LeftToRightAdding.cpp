#include "LeftToRightAdding.hpp"
#include "Container.hpp"
#include "Component.hpp"
#include "Rect.hpp"
Component* LeftToRightAdding::task(const Container* container, Component* component) {
	size_t nComp = container->getComponentCount();
	if (nComp) {
		FloatRect rect = container->getComponent(nComp - 1)->getGlobalBounds();
		component->setPosition(rect.position() + Vector2f(rect.width));
	}
	else {
		FloatRect rect = container->getGlobalBounds();
		component->setPosition(rect.position());

	}
	return component;
}
