#include <iostream>
#include "node.h"
#include <math.h>

class edge
{
	node begin;
	node end;
	double weight;

public:
	//edge(int i, int z){}
	edge(node _begin, node _end)
	{
		begin = _begin;
		end = _end;
		CalcWeigth();
	}
	void CalcWeigth()
	{
		weight = sqrt(pow((begin.get_x() - end.get_x()), 2) + pow((begin.get_y() - end.get_y()), 2));
	}
};