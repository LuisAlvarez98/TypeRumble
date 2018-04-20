#include "Player.h"
#include "HealthBar.h"
#include <fstream>
#include <cstdlib> 

vector<String> words;

string wordRandom() {
	int index;
	index = rand() % words.size();

	return words[index];
}
int main()
{
	int p = 0;
	sf::RenderWindow window(sf::VideoMode(500, 500), "TypeRumble");
	Player playerOne;
	HealthBar hb1(Vector2f(0,0));
	HealthBar hb2(Vector2f(window.getSize().x - 200,0));
	HealthBar hb3(Vector2f(0, 0), Color::Black);
	string oracion;
	string theWord = "default";
	ifstream ifarchivo;
	ifarchivo.open("sentences.txt");

	while (getline(ifarchivo, oracion)) {
		words.push_back(oracion);
		cout << oracion << "\n";
	}

	Font font;

	if (!font.loadFromFile("Raleway-Regular.ttf")) {
		cout << "error" << "\n";
	}
	Text text;
	Text word;
	bool flag = true;
	word.setFont(font);
	word.setFillColor(Color::Black);
	


	
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
				//Text handler
			case Event::TextEntered:
				if (event.text.unicode == 8) {
					if (sentence.size() > 0) {
						sentence.erase(sentence.size() - 1, 1);
					}
				}
				else if (event.text.unicode < 127) {
					sentence += static_cast<char>(event.text.unicode);
					if (sentence == word.getString()) {
						sentence = "";
						theWord = wordRandom();
						break;
					}

				}
				break;
			}
		}
		window.clear(Color::White);
		//playerOne.draw(&window);
		hb3.draw(&window);
		
		hb1.draw(&window);
		hb2.draw(&window);
		
		//hb1.inflictDamage();
		
		word.setString(theWord);
		text.setString(sentence);
		window.draw(text);
		window.draw(word);
		word.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));
		window.display();
	
	}
	
	ifarchivo.close();
	return 0;
}