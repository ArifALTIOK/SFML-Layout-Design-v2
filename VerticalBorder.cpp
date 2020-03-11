#include "VerticalBorder.hpp"
#include "Container.hpp"
Component* VerticalBorder::task(const Container* container, Component* component) {
	Component* retval = behaviour->task(container, component);
	if (!sBound.empty()) {
		Vector2f pref = container->getPreferredSize();
		FloatRect rect = sBound.back();
		FloatRect cRect = retval->getGlobalBounds();
		rect.left = min(rect.left, cRect.left);
		rect.top = min(rect.top, cRect.top);
		rect.width = max(rect.width, cRect.width);
		rect.height += cRect.height;
		if (pref.x <= rect.left + rect.width && pref.y <= rect.top + rect.height) {
			return NULL;
		}
		if (pref.y <= rect.height) {
			Vector2f pos = container->getPosition();
			rect = sBound.back();
			pos.x = rect.left + rect.width;
			component->setPosition(pos);
			sBound.push_back(component->getGlobalBounds());
		}
		else
			sBound.back() = rect;
	}
	else {
		sBound.push_back(component->getGlobalBounds());
	}
	return retval;
}