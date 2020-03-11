#include <iostream>
#include "Layout.hpp"
#include "LayoutManager.hpp"
#include "RelativeBehaviour.hpp"
#include "RandomBehaviour.hpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(0));
	Layout l(
		new LayoutManager(
			new RandomAdding(FloatRect(0,0,300,300)),
			new RandomRemove
		)
	);
	
	l.setOrigin({ 80, 80 });

	for (int i = 0; i < 12; i++) {
		Component* comp = new Component;
		l.addLayoutComponent(comp);
	}
	
	l.print();
	system("pause");
	return 0;
}
//template<typename T1, typename T2>
//constexpr auto min(T1 x, T2 y) { return x < y ? x : y; }
//
//template<typename T1, typename T2>
//constexpr auto max(T1 x, T2 y) { return x > y ? x : y; }
//
//class MinSizeCalculator {
//protected:
//	FloatRect bound;
//	virtual void CalculateMinSize(const Container* container, size_t nComp)const = 0;
//public:
//	FloatRect getMinSize(const Container* container) {
//		size_t nComp = container->getComponentCount();
//		if (nComp) {
//			const Component* comp = container->getComponent(0);
//			bound = comp->getGlobalBounds();
//			CalculateMinSize(container,nComp);
//		}
//		return bound;
//	}
//
//};
//
//
//class HorizontalMinSizeCalculator : public MinSizeCalculator{
//public:
//	void CalculateMinSize(const Container* container,size_t nComp) {
//		for (int i = 1; i < nComp; i++) {
//			const Component* comp = container->getComponent(i);
//			FloatRect cBound = comp->getGlobalBounds();
//			bound.left = min(bound.left, cBound.left);
//			bound.top = min(bound.top, cBound.top);
//			bound.width += cBound.left - bound.left + cBound.width;
//			bound.height = max(bound.height, cBound.top + cBound.height);
//		}
//	}
//};
//
//
//
//class VerticalMinSizeCalculator : public MinSizeCalculator {
//public:
//	void CalculateMinSize(const Container* container, size_t nComp) {
//		for (int i = 1; i < nComp; i++) {
//			const Component* comp = container->getComponent(i);
//			FloatRect cBound = comp->getGlobalBounds();
//			bound.width = max(bound.width,cBound.left + cBound.width);
//			bound.height += max(bound.height, cBound.top + cBound.height);
//		}
//	}
//};
//
//class BorderBehaviour : public DecaratorBehaviour
//{
//protected:
//	Vector2f prefferredSize;
//public:
//	using DecaratorBehaviour::DecaratorBehaviour;
//
//	virtual Component* decision(Component* component) = 0;
//	Component* task(const Container* container, Component* component) {
//		Component* retval = behaviour->task(container, component);
//
//		prefferredSize = container->getPreferredSize();
//		retval = decision(retval);
//		return retval;
//	}
//};

//class Vertical : public BorderBehaviour {
//public:
//	using BorderBehaviour::DecaratorBehaviour;
//	Component* task(const Container* container, Component* component) {
//		return NULL;
//	}
//};



