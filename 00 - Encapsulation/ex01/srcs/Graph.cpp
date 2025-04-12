#include "../includes/Graph.hpp"

Graph::Graph(): _maxX(0), _maxY(0) {}
Graph::~Graph() {}

void Graph::addPoint(const Vector2& point) {
	if (point.x > _maxX)
		_maxX = static_cast<int>(point.x);
	if (point.y > _maxY)
		_maxY = static_cast<int>(point.y);	
	points.push_back(point);
}

void Graph::displayPoints() const {
    char grid[_maxY][_maxX];

    for (int y = 0; y <= _maxY; ++y) {
        for (int x = 0; x <= _maxX; ++x)
            grid[y][x] = '.';
    }

    for (std::vector<Vector2>::const_iterator point = points.begin(); point != points.end(); ++point) {
        int x = static_cast<int>(point->x);
        int y = static_cast<int>(point->y);

        if (x >= 0 && x <= _maxX && y >= 0 && y <= _maxY)
            grid[y][x] = 'X';
    }

    for (int y = _maxY; y >= 0; --y) {
        for (int x = 0; x < _maxX + 1; ++x)
            std::cout << grid[y][x] << ' ';
        std::cout << std::endl;
    }
}