#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class HealthBar {
	private:
		RectangleShape bar;
		int maxHealth;
		int hp;
		Vector2f pos;
		Vector2f size;

	public:
		//Normal hbar
		HealthBar(Vector2f _pos) {
			pos = _pos;
			hp = 200;
			bar = RectangleShape(Vector2f(hp, 20));
			bar.setPosition(pos);
			bar.setFillColor(Color::Green);

		}
		void setHp(RectangleShape bar) {
			this->bar = bar;
		}
		int getHp() {
			return hp;
		}
		void draw(RenderWindow *window) {
			window->draw(bar);
		}



};