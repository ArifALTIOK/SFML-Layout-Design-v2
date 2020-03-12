#include <iostream>
#include "Layout.hpp"
#include "LayoutManager.hpp"
#include "Shape.hpp"
#include "RandomBehaviour.hpp"
#include <SFML/Graphics.hpp>
using namespace std;




//class ShapeComponent : public Component {
//	sf::Shape& shape;
//public:
//	ShapeComponent(
//		sf::Shape& shape
//	) : 
//		shape(shape),
//		Component(
//			new ShapeTransformable(shape),
//			new NoGaps)
//		)
//};
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	sf::RectangleShape shape;
	ShapeAdapter
	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(100, 100));
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
				default:
					break;
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}


	/*
	Layout l(
		new LayoutManager(
			new RandomAdding(FloatRect(10,10,11,11)),
			new DefaultBehaviour
		),
		20,80
	);
	
	

	for (int i = 0; i < 12; i++) {
		Component* comp = new Component(new Rectangle({ 10,10 }));

		l.addLayoutComponent(comp);
	}
	
	l.print();*/
	system("pause");
	return 0;
}
