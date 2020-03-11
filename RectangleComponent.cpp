#include "RectangleComponent.hpp"
#include "Shape.hpp"

RectangleComponent::RectangleComponent(
	const Vector2f& size
) :
	Component(new Rectangle(size))
{	}

RectangleComponent::RectangleComponent(
	const Vector2f& size,
	ITransformable* transformable,
	IGaps* gaps
) :
	Component(
		new Rectangle(size),
		transformable,
		gaps
	)
{}

void RectangleComponent::setSize(const Vector2f& size) {
	static_cast<Rectangle*>(shape)->setSize(size);
}

Vector2f RectangleComponent::getSize()const {
	return static_cast<Rectangle*>(shape)->getSize();
}