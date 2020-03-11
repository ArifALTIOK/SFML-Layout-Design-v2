#pragma once
#include "Component.hpp"
class RectangleComponent : public Component {
public:
	RectangleComponent(
		const Vector2f& size
	);

	RectangleComponent(
		const Vector2f& size,
		ITransformable* transformable,
		IGaps* gaps
	);

	void setSize(const Vector2f& size);

	Vector2f getSize()const;
};