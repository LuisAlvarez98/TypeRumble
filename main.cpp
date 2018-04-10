#include "Player.h"
#include "HealthBar.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "TypeRumble");
	Player playerOne;
	HealthBar hb1(Vector2f(0,0));
	HealthBar hb2(Vector2f(window.getSize().x - 200,0));
	HealthBar hb3(Vector2f(0, 0), Color::Black);

	Font font;
	if (!font.loadFromFile("Raleway-Regular.ttf")) {
		cout << "error" << "\n";
	}
	Text text;
	text.setFont(font);
	text.setFillColor(Color::Red);
	//text.setString("hola");
	string sentence;
	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				window.close();
				break;
				//typing
			case Event::TextEntered:
				if (event.text.unicode < 128) {
					sentence += static_cast<char>(event.text.unicode);
				}
				break;
			}
		}
		text.setString(sentence);
		
		window.clear(Color::White);
		//playerOne.draw(&window);
		hb3.draw(&window);
		
		hb1.draw(&window);
		hb2.draw(&window);
	
		//hb1.inflictDamage();
		
		window.draw(text);
		window.display();
	}
	

	return 0;
}