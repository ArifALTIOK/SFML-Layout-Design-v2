#include "SFMLComponent.hpp"
#include "SFMLShape.hpp"
#include "IGaps.hpp"
#include "SFMLTransformable.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>



SFMLComponent::SFMLComponent(
	sf::Shape& shape
) :
	SFMLComponent(
		shape,
		new NoGaps
	)
{	}

SFMLComponent::SFMLComponent(
	sf::Shape& shape,
	IGaps* gaps
) :
	AdapterComponent(
		shape,
		new SFMLShape(shape),
		new SFMLTransformable(shape),
		gaps
	)
{	}


void SFMLComponent::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(adaptee, states);
}