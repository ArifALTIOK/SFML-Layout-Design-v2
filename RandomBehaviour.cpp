#include "RandomBehaviour.hpp"
#include "Component.hpp"
#include "RandGen.hpp"

RandomAdding::RandomAdding(
	float left,
	float top,
	float width,
	float height
) : 
	RandomAdding(
		FloatRect(left,top,width,height)
	)
{}

RandomAdding::RandomAdding(FloatRect range) 
	: m_range(range)
{	}

Component* RandomAdding::task(const Container* container, Component* component) {
	RandGen rd;
	Vector2f position(
		(float)rd.randReal(m_range.left, m_range.width),
		(float)rd.randReal(m_range.top, m_range.height)
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