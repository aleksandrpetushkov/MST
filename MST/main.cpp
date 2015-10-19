#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
#include <vector>

using namespace std;

void main()
{

	//load node
	string name_in_file = "file.txt";
	ifstream fs(name_in_file, ios::in);
	if(fs)
	{
		vector<node> nodes;
		
		while(!fs.eof())
		{
			int tmp;
			node ntmp;
			fs >> tmp;
			ntmp.set_id(tmp);
			fs >> tmp;
			ntmp.set_x(tmp);
			fs >> tmp;
			ntmp.set_y(tmp);
			nodes.push_back(ntmp);
		}
		cout << nodes.size()<<endl;
		for (int i = 0; i < nodes.size();++i)
		{
			nodes[i].print();
		}
		system("pause");




		fs.close();
	}
	else
	{
		cerr << "Error: cannot open file" << endl;
		system("pause");
	}

	//cout << "Hello world";
}