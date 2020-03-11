#include "RandomBehaviour.hpp"
#include "Component.hpp"

RandomAdding::RandomAdding(FloatRect range) 
	: m_range(range)
{

}

Component* RandomAdding::task(const Container* container, Component* component) {
	float xRange = m_range.width - m_range.left;
	float yRange = m_range.height - m_range.top;
	Vector2f position(
		fmod(rand(), xRange) + m_range.left,
		fmod(rand(), yRange) + m_range.top
	);
	component->setPosition(position);
	return component;
}

FloatRect RandomAdding::getRange()const {
	return m_range;
}

void RandomAdding::setRange(const FloatRect& range) {
	m_range = range;
}