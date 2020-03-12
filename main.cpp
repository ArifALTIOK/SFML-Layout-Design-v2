#include <iostream>
#include "Layout.hpp"
#include "LayoutManager.hpp"
#include "RandomBehaviour.hpp"
#include "SFMLComponent.hpp"
#include <SFML/Graphics.hpp>
using namespace std;
#include "RandGen.hpp"
int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	window.setFramerateLimit(24);
	
	Layout layout;
	layout.setLayoutManager(new LayoutManager(
		new RandomAdding(0,0,500,500),
		new RandomRemove
	));

	RandGen random;
	for (int i = 0; i < 12; i++) {
		sf::RectangleShape* shape = new sf::RectangleShape;
		shape->setSize(sf::Vector2f(50, 50));
		int rand = random.randInt(3);
		switch (rand)
		{
		case 0:
			shape->setFillColor(sf::Color::Red);
			break;
		case 1:
			shape->setFillColor(sf::Color::Green);
			break;
		case 2:
			shape->setFillColor(sf::Color::Blue);
			break;
		default:
			break;
		}

		SFMLComponent *c = new SFMLComponent(*shape);
		layout.addLayoutComponent(c);
	}

	int counter = 0;
	sf::Clock clock;
	int direction = 1;
	sf::Time t1;
	sf::Time t2;
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
			layout.move(direction, 0);
			t1 = clock.getElapsedTime();
		}
		

		if ((clock.getElapsedTime() - t2).asSeconds() > 2) {
			direction *= -1;
			layout.rotateAllComponent(45);
			t2 = clock.getElapsedTime();
		}

		
		
	}

	system("pause");
	return 0;
}
