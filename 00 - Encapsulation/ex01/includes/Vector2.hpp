#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include <iostream>

using namespace std;

class Vector2
{
	public:
		float x;
		float y;

		Vector2(float x, float y);
		~Vector2();
};

#endif