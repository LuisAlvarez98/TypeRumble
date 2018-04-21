#include "Player.h"
#include "HealthBar.h"
#include <fstream>
#include <cstdlib> 

vector<String> words;

//Word random function
string wordRandom() {
	int index;
	index = rand() % words.size();

	return words[index];
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "TypeRumble");
	Player playerOne;
	HealthBar hb1(Vector2f(0,0));
	hb1.setHp(RectangleShape(Vector2f(200,20)));

	

	string oracion;
	string sentence;
	string theWord = "default";
	ifstream ifarchivo;
	Font font;
	Text text;
	Text word;
	Text hp;


	ifarchivo.open("sentences.txt");

	while (getline(ifarchivo, oracion)) {
		words.push_back(oracion);
		cout << oracion << "\n";
	}


	if (!font.loadFromFile("Raleway-Regular.ttf")) {
		cout << "error" << "\n";
	}
	
	//Sentences
	word.setFont(font);
	word.setFillColor(Color::Black);
	word.setCharacterSize(10);
	//Typed text
	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setCharacterSize(10);
	

	//Main loop
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
		hb1.draw(&window);
		
		word.setString(theWord);
		word.setPosition(Vector2f(0,50));

		text.setString(sentence);
		text.setPosition(Vector2f(0, 0));


		window.draw(text);
		window.draw(word);
		window.display();
	
	}
	
	ifarchivo.close();
	return 0;
}