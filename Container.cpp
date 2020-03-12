#include "Container.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
void Container::addComponent(Component* component) {
	//cout << __FUNCSIG__ << endl;
	addComponent(component, getComponentCount());
}

void Container::addComponent(Component* component, size_t n) {
	//cout << __FUNCSIG__ << endl;
	components.insert(components.begin() + n, component);
}

void Container::removeComponent(size_t n) {
	//cout << __FUNCSIG__ << endl;
	if (n < getComponentCount()) {
		Component* c = components[n];
		delete c;
		components.erase(components.begin() + n);
	}
}

void Container::removeComponent(Component* component) {
	//cout << __FUNCSIG__ << endl;
	size_t nComp = getComponentCount();
	for (int i = 0; i < nComp; i++) {
		if (components[i] == component)
		{
			removeComponent(i);
			break;
		}
	}
}
Component* Container::getComponent(size_t n) {
	return components[n];
}


size_t Container::getComponentCount()const {
	return components.size();
}

const Component* Container::getComponent(size_t n)const {
	return components[n];
}

void Container::setPosition(const Vector2f& position) {
	Vector2f diff = position - getPosition();
	foreach([&](Component* c) {
		c->setPosition(c->getPosition() + diff);
	});
	Component::setPosition(position);
}
void Container::print()const {
	cout << "Container -> " << getPosition() << " " << getOrigin() << " " << getGlobalBounds() << endl;
	for (Component* c : components) {
		cout << "\t";
		c->print();
	}
}

Vector2f Container::getMinimumSize()const {
	return Vector2f(0, 0);
}

Vector2f Container::getPreferredSize()const {
	return Vector2f(0, 0);
}

void Container::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (Component* c : components)
		target.draw(*c, states);
}

