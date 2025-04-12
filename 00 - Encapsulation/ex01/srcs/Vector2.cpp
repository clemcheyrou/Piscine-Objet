#include "../includes/Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) 
{
	cout << GREEN << "Vector created: " << x << ", " << y << RESET << endl;
}

Vector2::~Vector2() {}