#pragma once
#include "ITransformable.hpp"
#include "IBounds.hpp"

class IComponent : public ITransformable, public IBounds {
public:
	virtual void print() const = 0;
};
