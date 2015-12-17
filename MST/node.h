#include <iostream>
#include <string>

using namespace std;

class node
{
private:
	unsigned int id=0;
	int x=0;
	int y=0;
public:

	node() {}
	node(int _id, int _x, int _y)
	{
		id = _id;
		x = _x;
		y = _y;
	}
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
	unsigned int get_id()
	{
		return id;
	}
	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}
	void print()
	{
		cout << "id - " << id << " x - " << x << " y - " << y << endl;
	}
};
