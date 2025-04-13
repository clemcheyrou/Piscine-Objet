#include "../includes/Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) 
{
	cout << GREEN << "Vector created: " << x << ", " << y << RESET << endl;
}

Vector2::~Vector2() {}

float Vector2::getX() const {
    return x;
}

void Vector2::setX(float val) {
    x = val;
}

float Vector2::getY() const {
    return y;
}

void Vector2::setY(float val) {
    y = val;
}