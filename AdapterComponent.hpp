#pragma once
#include "Adapter.hpp"
#include "Component.hpp"

template<typename Adaptee>
class AdapterComponent : public Adapter<Adaptee>, public Component {
public:
	AdapterComponent(
		Adaptee adaptee,
		Shape* shape,
		ITransformable* transformable,
		IGaps* gaps
	) :
		Adapter<Adaptee>(adaptee),
		Component(
			shape,
			transformable,
			gaps
		)
	{	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
};