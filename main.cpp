#include <iostream>
#include "Layout.hpp"
#include "LayoutManager.hpp"
#include "HorizontalBorder.hpp"
#include "Shape.hpp"
#include "TopToBottomBehaviour.hpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(0));
	
	Layout l(
		new LayoutManager(
			new HorizontalBorder(new TopToBottomAdding),
		//
			new DefaultBehaviour
		),
		20,80
	);
	
	

	for (int i = 0; i < 12; i++) {
		Component* comp = new Component(new Rectangle({ 10,10 }));

		l.addLayoutComponent(comp);
	}
	
	l.print();
	system("pause");
	return 0;
}
