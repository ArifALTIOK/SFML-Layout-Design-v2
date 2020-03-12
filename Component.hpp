#pragma once
#include "IComponent.hpp"
#include <SFML/Graphics/Drawable.hpp>
class Shape;
class IGaps;
using namespace std;
class Component : public IComponent,public sf::Drawable{
protected:
	Shape* shape;
	ITransformable* transformable;
	IGaps* gaps;
public:
	Component();

	Component(Shape* shape);
	
	Component(
		Shape* shape,
		ITransformable* transformable,
		IGaps* gaps
	);

	Vector2f getPosition()const;

	Vector2f getOrigin()const;

	Vector2f getScale()const;

	float getRotation()const;

	void setPosition(const Vector2f& position);

	void setOrigin(const Vector2f& origin);

	void setScale(const Vector2f& scale);

	void setRotation(float angle);

	void move(float x, float y);

	void move(const Vector2f& offset);

	void rotate(float angle);

	FloatRect getLocalBounds()const;

	FloatRect getGlobalBounds()const;

	virtual Vector2f getPreferredSize()const; // default shape->getDimension();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;

	void print()const {
		cout << "Component -> " << getPosition() << " " << getOrigin() << " " << getGlobalBounds() << endl;
	}
};