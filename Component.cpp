#include "Component.hpp"
#include "Shape.hpp"
#include "Transformable.hpp"
#include "IGaps.hpp"

Component::Component()
	:
	Component(new ShapeLess)
{	}

Component::Component(Shape* shape)
	: Component(shape, new Transformable, new NoGaps)
{	}

Component::Component(
	Shape* shape,
	ITransformable* transformable,
	IGaps* gaps
) :
	shape(shape),
	transformable(transformable),
	gaps(gaps)
{		}

Vector2f Component::getPosition()const {
	return transformable->getPosition();
}

Vector2f Component::getOrigin()const {
	return transformable->getOrigin();
}

Vector2f Component::getScale()const {
	return transformable->getScale();
}

float Component::getRotation()const {
	return transformable->getRotation();
}

void Component::setPosition(const Vector2f& position) {
	transformable->setPosition(position);
}

void Component::setOrigin(const Vector2f& origin) {
	transformable->setOrigin(origin);
}

void Component::setScale(const Vector2f& scale) {
	transformable->setScale(scale);
}

void Component::setRotation(float angle) {
	transformable->setRotation(angle);
}

void Component::move(float x, float y) {
	move(Vector2f(x, y));
}

void Component::move(const Vector2f& offset) {
	setPosition(getPosition() + offset);
}


void Component::rotate(float angle) {
	setRotation(getRotation() + angle);
}

FloatRect Component::getLocalBounds()const {
	Vector2f dim = shape->getDimension();
	dim.x += gaps->getHorizontalGaps().total();
	dim.y += gaps->getVerticalGaps().total();
	return FloatRect({ 0,0 }, dim);
}

FloatRect Component::getGlobalBounds()const {
	Vector2f dim = shape->getDimension();
	dim.x += gaps->getHorizontalGaps().total();
	dim.y += gaps->getVerticalGaps().total();
	return FloatRect(getPosition() - getOrigin(), dim);
}

Vector2f Component::getPreferredSize() const
{
	return shape->getDimension();
}
