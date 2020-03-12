#pragma once
#include "Shape.hpp"
#include <SFML/Graphics/Shape.hpp>
class SFMLShape : public AdapterShape<sf::Shape&> {
public:
	using AdapterShape<sf::Shape&>::AdapterShape;

	Vector2f getDimension()const;
};