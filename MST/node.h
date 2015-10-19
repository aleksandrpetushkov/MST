#include <iostream>
#include <string>

using namespace std;


class node
{
	int id=0;
	int x=0;
	int y=0;
public:
	node() {}
	node(int in[])
	{
		id = in[0];
		x = in[1];
		y = in[2];
	}
	void set_id(int _i)
	{
		id = _i;
	}
	void set_x(int _i)
	{
		x = _i;
	}
	void set_y(int _i)
	{
		y = _i;
	}
	void print()
	{
		cout << "id - " << id << " x - " << x << " y - " << y << endl;
	}
};
