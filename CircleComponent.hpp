#pragma once
#include "Component.hpp"
class CircleComponent : public Component {
public:
	CircleComponent(
		float radius
	);

	CircleComponent(
		float radius,
		ITransformable* transformable,
		IGaps* gaps
	);

	void setRadius(float radius);

	float getRadius()const;
};