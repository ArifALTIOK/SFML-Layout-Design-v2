#include "CircleComponent.hpp"
#include "Shape.hpp"
CircleComponent::CircleComponent(
	float radius
) :
	Component(
		new Circle(radius)
	)
{	}

CircleComponent::CircleComponent(
	float radius,
	ITransformable* transformable,
	IGaps* gaps
) :
	Component(
		new Circle(radius),
		transformable,
		gaps
	)
{	}

void CircleComponent::setRadius(float radius) {
	static_cast<Circle*>(shape)->setRadius(radius);
}

float CircleComponent::getRadius()const {
	return static_cast<Circle*>(shape)->getRadius();
}