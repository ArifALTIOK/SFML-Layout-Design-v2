#include "CircleBehaviour.hpp"
#include "Container.hpp"
#include "Component.hpp"
#ifndef M_PI
#define M_PI 3.141592
#endif
CircleAdding::CircleAdding(
	float radius,
	float angle
) :
	m_radius(radius),
	m_angle(angle)
{	}

Component* CircleAdding::task(const Container* container, Component* component) {
	size_t nComp = container->getComponentCount();
	float rd = static_cast<float>(nComp * m_angle * M_PI / 180.0);
	Vector2f pos(m_radius * cos(rd), m_radius* sin(rd));
	component->setPosition(pos + container->getOrigin());
	return component;
}

float CircleAdding::getRadius()const {
	return m_radius;
}
void CircleAdding::setRadius(float radius) {
	m_radius = radius;
}