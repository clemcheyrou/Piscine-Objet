#ifndef GRAPH_HPP
# define GRAPH_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include <iostream>
#include <vector>
#include "Vector2.hpp"

using namespace std;

class Graph
{
	private:
    	std::vector<Vector2> points;
		int _maxX;
		int _maxY;

	public:
		Graph();
		~Graph();
		void addPoint(const Vector2& point);
		void displayPoints() const;
};

#endif