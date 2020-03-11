#pragma once
#include "Behaviour.hpp"
#include "Rect.hpp"

class RandomAdding : public AddingBehaviour
{
	FloatRect m_range;
public:
	RandomAdding(FloatRect rangle);

	Component* task(const Container* container, Component* component);

	FloatRect getRange()const;
	void setRange(const FloatRect& range);
};

struct RandomRemove : DefaultBehaviour {	};