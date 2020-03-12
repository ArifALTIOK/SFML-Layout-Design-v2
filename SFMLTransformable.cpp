#include "SFMLTransformable.hpp"

Vector2f SFMLTransformable::getPosition()const {
	return Vector2Converter<sf::Vector2f, Vector2f>::convert(adaptee.getPosition());
}

Vector2f SFMLTransformable::getOrigin()const {
	return Vector2Converter<sf::Vector2f, Vector2f>::convert(adaptee.getOrigin());
}

Vector2f SFMLTransformable::getScale()const {
	return Vector2Converter<sf::Vector2f, Vector2f>::convert(adaptee.getOrigin());
}

float SFMLTransformable::getRotation()const {
	return adaptee.getRotation();
}

void SFMLTransformable::setPosition(const Vector2f& position) {
	adaptee.setPosition(Vector2Converter<Vector2f, sf::Vector2f>::convert(position));
}

void SFMLTransformable::setOrigin(const Vector2f& origin) {
	adaptee.setOrigin(Vector2Converter<Vector2f, sf::Vector2f>::convert(origin));
}

void SFMLTransformable::setScale(const Vector2f& scale) {
	adaptee.setScale(Vector2Converter<Vector2f, sf::Vector2f>::convert(scale));
}

void SFMLTransformable::setRotation(float angle) {
	adaptee.setRotation(angle);
}