#pragma once
#include "Component.hpp"
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

class LayoutManager;

class Container : public Component {
	using Components = std::vector<Component*>;
	using Iterator = typename Components::iterator;
	Components components;
protected:
	friend LayoutManager;
	void addComponent(Component* component);

	void addComponent(Component* component, size_t n);

	void removeComponent(size_t n);

	void removeComponent(Component* component);

	Component* getComponent(size_t n);

public:
	
	size_t getComponentCount()const;

	const Component* getComponent(size_t n)const;

	void setPosition(const Vector2f& position);

	void print()const;
	
	virtual Vector2f getMinimumSize()const;

	virtual Vector2f getPreferredSize()const;
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	
	void foreach(std::function<void(Component*)> function);
	template<typename Retval>
	Retval foreach(std::function<Retval(Component*)> function);
};


inline void Container::foreach(std::function<void(Component*)> function)
{
	for (Component* c : components) {
		function(c);
	}
}

template<typename Retval>
inline Retval Container::foreach(std::function<Retval(Component*)> function)
{
	Retval retval;
	for (Component* c : components) {
		retval = function(c);
	}
	return retval;
}
