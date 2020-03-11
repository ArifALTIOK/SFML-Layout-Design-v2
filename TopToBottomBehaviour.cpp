#include "TopToBottomBehaviour.hpp"
#include "Container.hpp"
Component* TopToBottomAdding::task(const Container* container, Component* component) {
	size_t nComp = container->getComponentCount();
	if (nComp) {
		FloatRect rect = container->getComponent(nComp - 1)->getGlobalBounds();
		component->setPosition(rect.position() + Vector2f(0,rect.height));
	}
	else {
		FloatRect rect = container->getGlobalBounds();
		component->setPosition(rect.position());
	}
	return component;
}
