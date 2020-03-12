#include "SFMLShape.hpp"

Vector2f SFMLShape::getDimension()const {
	sf::FloatRect rect = adaptee.getLocalBounds();
	return Vector2f(rect.width, rect.height);
}