#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
#include <vector>
#include "edge.h"

using namespace std;

void main()
{

	
	string name_in_file = "file.txt";
	ifstream fs(name_in_file, ios::in);
	if(fs)
	{
		vector<node> nodes;
		vector<edge> edges;
		
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
		for (unsigned int i = 0; i < nodes.size();++i)
		{
			nodes[i].print();
		}
		for (unsigned int j = 0 ; j < nodes.size()-1; ++j)
		{
			edge *tmp;
			for (unsigned int i =j+1; i < nodes.size(); ++i)
			{
				//edges.push_back(*(new edge((nodes[j]), nodes[i])));
			}
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