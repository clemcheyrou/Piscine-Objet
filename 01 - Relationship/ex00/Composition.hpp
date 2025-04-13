#include <iostream> 
using namespace std; 

struct Position {
    int x;
	int y;
};

struct Statistic {
    int level;
	int exp;
};

class Worker
{
	public:
		Position x;
		Statistic y;

		Worker(Position pos, Statistic stat) : x(pos), y(stat) {}
		~Worker() {};
};