#pragma once
#include "AdapterComponent.hpp"
namespace sf {
	class Shape;
	class RenderTarget;
	class RenderStates;
}


class SFMLComponent : public AdapterComponent<sf::Shape&> {
public:

	SFMLComponent(
		sf::Shape& shape
	);

	SFMLComponent(
		sf::Shape& shape,
		IGaps* gaps
	);

	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};