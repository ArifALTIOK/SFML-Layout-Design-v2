#pragma once
#include "Container.hpp"
class LayoutManager;
class Layout : public Container {
	LayoutManager* manager;
	Vector2f preferredSize;
public:
	Layout(
		Vector2f size,
		LayoutManager* manager = NULL
	);

	Layout(
		float x = 0,
		float y = 0,
		LayoutManager* manager = NULL
	);

	void setLayoutManager(LayoutManager* manager);

	void addLayoutComponent(Component* component);

	void removeLayoutComponent(Component* component);

	Vector2f getPreferredSize()const {
		return preferredSize;
	}
};