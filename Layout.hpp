#pragma once
#include "Container.hpp"
class LayoutManager;
class Layout : public Container {
	LayoutManager* manager;
public:
	Layout();
	Layout(
		LayoutManager* manager
	);

	void setLayoutManager(LayoutManager* manager);

	void addLayoutComponent(Component* component);

	void removeLayoutComponent(Component* component);
};