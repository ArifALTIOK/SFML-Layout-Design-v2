#pragma once
#include "Behaviour.hpp"
#include "Rect.hpp"

class RandomAdding : public AddingBehaviour
{
	FloatRect m_range;
public:
	RandomAdding(
		float left = 0,
		float top = 0,
		float width = 1,
		float height = 1
	);

	RandomAdding(FloatRect rangle);

	Component* task(const Container* container, Component* component);

	FloatRect getRange()const;

	void setRange(const FloatRect& range);
};

struct RandomRemove : DefaultBehaviour {	};