#include <iostream>
#include "Layout.hpp"
#include "LayoutManager.hpp"



int main() {


	return 0;
}
/*

//Layout - LayoutManager kullanim ornegi

#include <iostream>
#include "Layout.hpp"
#include "LayoutManager.hpp"
#include "RandomBehaviour.hpp"
#include "SFMLComponent.hpp"
#include <SFML/Graphics.hpp>
#include "LeftToRightAdding.hpp"
#include "HorizontalBorder.hpp"
using namespace std;
#include "RandGen.hpp"
int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	window.setFramerateLimit(24);
	
	Layout layout(800, 600);
	layout.setLayoutManager(
		new LayoutManager(
			new HorizontalBorder(
				new LeftToRightAdding
			),
			new RandomRemove
		)
	);
	
	//Layout layout(
	//	800,
	//	600,
	//	new LayoutManager(
	//		new HorizontalBorder(
	//			new LeftToRightAdding
	//		),
	//		new RandomRemove
	//	)
	//);
	

	RandGen random;
	for (int i = 0; i < 50000; i++) {
		sf::Shape* shape = new sf::RectangleShape(sf::Vector2f(5, 5));
		//sf::Shape* shape = new sf::CircleShape(2);
		shape->setFillColor(sf::Color(random.randInt(0, 255), random.randInt(0, 255), random.randInt(0, 255)));

		SFMLComponent *c = new SFMLComponent(shape);
		layout.addLayoutComponent(c);
	}

	layout.foreach([](Component* c) {
		c->setOrigin(c->getPreferredSize() / 2);
	});

	sf::Clock clock;
	sf::Time t1;
	sf::Time t2;
	int direction = 1;
	
	t1 = t2 = clock.getElapsedTime();
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

		if ((clock.getElapsedTime() - t1).asMilliseconds() > .1){
			window.clear();
			window.draw(layout);
			window.display();
			layout.foreach([&](Component* c) {
				if (random.randReal() < .2)
					c->move(random.randInt(-5,5), random.randInt(-5,5));
			});
			t1 = clock.getElapsedTime();
		}
		
		
		if ((clock.getElapsedTime() - t2).asSeconds() > 2) {
			layout.foreach([&](Component* c) {
				if(random.randReal() < 0.1)
					c->rotate(random.randReal(-45,45));
			});

			t2 = clock.getElapsedTime();
		}
	}

	system("pause");
	return 0;
}
*/