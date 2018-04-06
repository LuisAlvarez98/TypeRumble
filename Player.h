#include <SFML/Graphics.hpp>
using namespace sf;

#pragma once
class Player {
	private:
		CircleShape shape;
		int size;
		int health;
		Vector2f pos;
	public:
		Player();
		Player(Vector2f, int);
		void draw(RenderWindow*);
		
};
//Default
Player::Player() {
	pos = Vector2f(0, 0);
	shape = CircleShape(10);
	health = 100;
}
//Nigger
Player::Player(Vector2f _pos, int _size) {
	pos = _pos;
	size = _size;
	shape = CircleShape(size);
	shape.setPosition(pos);
	shape.setFillColor(Color::Green);

}
//Draw Method
void Player::draw(RenderWindow *window) {
	window->draw(shape);
}
