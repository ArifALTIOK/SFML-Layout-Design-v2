#pragma once
#include "Behaviour.hpp"
class CircleAdding : public AddingBehaviour
{
	float m_radius;
	float m_angle;
public:
	CircleAdding(
		float radius,
		float angle = 30
	);

	Component* task(const Container* container, Component* component);
	float getRadius()const;
	void setRadius(float radius);
};

