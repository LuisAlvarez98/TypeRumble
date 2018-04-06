#include "Player.h"
#include "HealthBar.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "TypeRumble");
	Player playerOne;
	HealthBar hb1(Vector2f(0,0));
	HealthBar hb2(Vector2f(window.getSize().x - 200,0));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//playerOne.draw(&window);
		hb1.draw(&window);
		hb2.draw(&window);

		window.display();
	}

	return 0;
}