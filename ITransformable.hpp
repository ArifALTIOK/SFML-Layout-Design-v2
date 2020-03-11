#pragma once
#include "Rect.hpp"

__interface IReadTransformable {
	virtual Vector2f getPosition()const = 0;
	virtual Vector2f getOrigin()const = 0;
	virtual Vector2f getScale()const = 0;
	virtual float getRotation()const = 0;
};

__interface IWriteTransformable {
	virtual void setPosition(const Vector2f&) = 0;
	virtual void setOrigin(const Vector2f&) = 0;
	virtual void setScale(const Vector2f&) = 0;
	virtual void setRotation(float) = 0;
};


__interface ITransformable : IReadTransformable, IWriteTransformable {
	
};

template<typename Adaptee>
class AdapterTransformable : public ITransformable{
protected:
	Adaptee transformable;
public:
	AdapterTransformable(
		Adaptee transformable
	) : transformable(transformable)
	{}
};

using DecaratorTransformable = AdapterTransformable<ITransformable*>;

