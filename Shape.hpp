#pragma once
#include "Vector2.hpp"
#include "Adapter.hpp"
class Shape {
public:
	virtual Vector2f getDimension() const = 0;
};

class ShapeLess : public Shape {
public:
	Vector2f getDimension()const {
		return Vector2f(0, 0);
	}
};

class Rectangle : public Shape {
	Vector2f m_size;
protected:
	Vector2f getDimension()const {
		return getSize();
	}
public:
	Rectangle(const Vector2f& size)
	{
		setSize(size);
	}

	Vector2f getSize()const {
		return m_size;
	}

	void setSize(const Vector2f& size) {
		m_size = size;
	}
};

class Circle : public Shape {
protected:
	float m_radius;
	Vector2f getDimension()const {
		return Vector2f(m_radius, m_radius);
	}

public:
	Circle(
		float radius
	) :
		m_radius(radius)
	{}

	float getRadius()const {
		return m_radius;
	}

	void setRadius(float radius) {
		m_radius = radius;
	}
};

template<typename Adaptee>
class AdapterShape : public Shape, public Adapter<Adaptee> {
public:
	using Adapter<Adaptee>::Adapter;
};