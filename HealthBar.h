#include <SFML/Graphics.hpp>
using namespace sf;

class HealthBar {
	public:
		HealthBar() {
			pos = Vector2f(0, 0);
			maxHealth = 100;
			bar = RectangleShape(Vector2f(200,20));
			bar.setPosition(pos);
			bar.setFillColor(Color::Green);
		}
		HealthBar(Vector2f pos) {
			this->pos = pos;
			maxHealth = 100;
			bar = RectangleShape(Vector2f(200, 20));
			bar.setPosition(pos);
			bar.setFillColor(Color::Green);

		}
		void draw(RenderWindow *window) {
			window->draw(bar);
		}

	private:
		RectangleShape bar;
		int maxHealth;
		Vector2f pos;
		Vector2f size;


};