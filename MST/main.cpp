#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
#include <vector>
#include "edge.h"
#include <algorithm>    // std::sort

using namespace std;

void main()
{
	string name_in_file = "file.txt";
	ifstream fs(name_in_file, ios::in);
	if(fs)
	{
		vector<node> nodes;
		vector<edge> edges;
		vector<edge> edges_ost;
		
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
		fs.close();
		cout << nodes.size()<<endl;
		for (unsigned int i = 0; i < nodes.size();++i)
		{
			nodes[i].print();
		}
		
		//загружаем ноды
		for (unsigned int j = 0 ; j < nodes.size()-1; ++j) 
		{
			for (unsigned int i =j+1; i < nodes.size(); ++i)
			{
				edges.push_back(*(new edge((nodes[j]), nodes[i])));
			}
		}
		//*
		for (unsigned int i = 0; i < edges.size();++i)
		{
			cout << i+1<<" - "<< edges[i].getBegin().get_id()<<" "<< edges[i].getEnd().get_id()<<" "<< edges[i].get_weight() << endl;
		}

		//*/
		cout << "----------------------------------------------------------\n";
		sort(edges.begin(), edges.end()); // Сортеруем вектор, для этого в классе edges перегуржены операторы "<" "==" для сравнения.

		for (unsigned int i = 0; i < edges.size(); ++i)
		{
			cout << i + 1 << " - " << edges[i].getBegin().get_id() << " " << edges[i].getEnd().get_id() << " " << edges[i].get_weight() << endl;
		}
		vector<int> listNodes;
		for (unsigned int i = 0; i < edges.size() ; ++i)
		{
			bool b = false;
			bool e = false;
			for (unsigned int j = 0; j < listNodes.size(); ++j) 
			{
				if (listNodes[j] == edges[i].getBegin().get_id())
				{
					b = true;
				}
				if (listNodes[j] == edges[i].getEnd().get_id()) 
				{
					e = true;
				}
			}
			if (b&&e) {	}
			else  
			{
				if (!b) 
				{
					listNodes.push_back(edges[i].getBegin().get_id());
				}
				if (!e) 
				{
					listNodes.push_back(edges[i].getEnd().get_id());
				}
				edges_ost.push_back(edges[i]);
			}
		}
		cout << edges_ost.size() << endl;
		
		system("pause");

		
	}
	else
	{
		cerr << "Error: cannot open file" << endl;
		system("pause");
	}

		
	//cout << "Hello world";
}