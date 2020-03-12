#pragma once
#include "Container.hpp"
class LayoutManager;
class Layout : public Container {
	LayoutManager* manager;
	Vector2f preferredSize;
public:
	Layout();
	Layout(
		LayoutManager* manager,
		float x = 0,
		float y = 0
	);

	void setLayoutManager(LayoutManager* manager);

	void addLayoutComponent(Component* component);

	void removeLayoutComponent(Component* component);

	void rotateAllComponent(float angle);

	Vector2f getPreferredSize()const {
		return preferredSize;
	}
};