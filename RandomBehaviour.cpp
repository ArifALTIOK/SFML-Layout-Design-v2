#include "RandomBehaviour.hpp"
#include "Component.hpp"
#include "RandGen.hpp"
RandomAdding::RandomAdding(FloatRect range) 
	: m_range(range)
{	}

Component* RandomAdding::task(const Container* container, Component* component) {
	RandGen rd;
	Vector2f position(
		rd.randReal(m_range.left, m_range.width),
		rd.randReal(m_range.top, m_range.height)
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