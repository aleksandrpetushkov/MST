#include <iostream>
#include "node.h"
#include <math.h>

class edge
{


public:
	edge(node&  _begin, node& _end)
	{
		begin = _begin;
		end = _end;
		CalcWeigth();
	}
	edge() {}
	
	void set(node _begin, node _end)
	{
		begin = _begin;
		end = _end;
		CalcWeigth();
	}


	void CalcWeigth()
	{
		weight = sqrt(pow((begin.get_x() - end.get_x()), 2) + pow((begin.get_y() - end.get_y()), 2));
	}
	double get_weight()
	{
		return weight;
	}
	node getBegin()
	{
		return begin;
	}
	node getEnd()
	{
		return end;
	}
	bool operator<(const edge &right)const
	{
		return(this->weight < right.weight);
	}
	bool operator==(const edge &right)const
	{
		return(this->weight == right.weight);
	}
protected:
	node begin;
	node end;
	double weight;
};
