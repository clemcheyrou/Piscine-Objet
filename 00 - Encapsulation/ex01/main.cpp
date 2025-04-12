#include "includes/Graph.hpp"

int main() {
    Graph graph;

    graph.addPoint(Vector2(0.0f, 0.0f));
    graph.addPoint(Vector2(2.0f, 2.0f));
    graph.addPoint(Vector2(4.0f, 2.0f));

    graph.displayPoints();

	return (0);
}