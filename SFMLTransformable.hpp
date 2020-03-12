#pragma once
#include "ITransformable.hpp"
#include <SFML/Graphics/Transformable.hpp>

class SFMLTransformable : public AdapterTransformable<sf::Transformable&> {
public:
	using AdapterTransformable<sf::Transformable&>::AdapterTransformable;

	Vector2f getPosition()const;

	Vector2f getOrigin()const;

	Vector2f getScale()const;

	float getRotation()const;

	void setPosition(const Vector2f& position);

	void setOrigin(const Vector2f& origin);

	void setScale(const Vector2f& scale);

	void setRotation(float angle);
};