#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "gtest\gtest.h"
#include "Kruskal.h"


using namespace std;

TEST(Kruskal)
{
	vector<node> nodes;
	vector<edge> edges;
	vector<edge> edges_ost;
	vector<edge> edges_ost_tst;

	edges_ost_tst.push_back(*(new edge(*new node(3, 9, 1), *new node(7, 9, 3))));
	edges_ost_tst.push_back(*(new edge(*new node(3, 9, 1), *new node(5, 13, 2))));
	edges_ost_tst.push_back(*(new edge(*new node(2, 3, 11), *new node(4, 0, 15))));
	edges_ost_tst.push_back(*(new edge(*new node(4, 0, 15), *new node(6, 5, 18))));
	edges_ost_tst.push_back(*(new edge(*new node(2, 3, 11), *new node(7, 9, 3))));
	edges_ost_tst.push_back(*(new edge(*new node(1, 20, 30), *new node(6, 5, 18))));


	node ntmp;
	ntmp.set_id(1);
	ntmp.set_x(20);
	ntmp.set_y(30);
	nodes.push_back(ntmp);

	ntmp.set_id(2);
	ntmp.set_x(3);
	ntmp.set_y(11);
	nodes.push_back(ntmp);

	ntmp.set_id(3);
	ntmp.set_x(9);
	ntmp.set_y(1);
	nodes.push_back(ntmp);

	ntmp.set_id(4);
	ntmp.set_x(0);
	ntmp.set_y(15);
	nodes.push_back(ntmp);

	ntmp.set_id(5);
	ntmp.set_x(13);
	ntmp.set_y(2);
	nodes.push_back(ntmp);
	
	ntmp.set_id(6);
	ntmp.set_x(5);
	ntmp.set_y(18);
	nodes.push_back(ntmp);
	
	ntmp.set_id(7);
	ntmp.set_x(9);
	ntmp.set_y(3);
	nodes.push_back(ntmp);
	
	/*
	edges_ost_tst[0] = *new edge();
	edges_ost_tst[0].
	//*/

	
	for (unsigned int j = 0; j < nodes.size() - 1; ++j)
	{
		for (unsigned int i = j + 1; i < nodes.size(); ++i)
		{
			edges.push_back(*(new edge((nodes[j]), nodes[i])));
		}
	}
	Kruskal kruskal(edges);
	edges_ost = kruskal.get_ost();
	EXPECT_EQ(21, kruskal.get_numberof_edges());
	EXPECT_EQ(6, kruskal.get_numberof_edges_ost());
	for (unsigned int i = 0; i != 6;++i)
	{
		EXPECT_EQ(edges_ost_tst[i], edges_ost[i]);
	}
	//for (unsigned int i = 0; )

}


int main(int argc, char* argv[])
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
			int tmp(0);
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
		//*Out nodes:
		cout << "Nodes:" << endl;
		for (unsigned int i = 0; i < nodes.size();++i)
		{
			nodes[i].print();
		}
		//*/
		//загружаем ноды
		for (unsigned int j = 0 ; j < nodes.size()-1; ++j) 
		{
			for (unsigned int i =j+1; i < nodes.size(); ++i)
			{
				edges.push_back(*(new edge((nodes[j]), nodes[i])));
			}
		}
		Kruskal kruskal(edges);

		edges_ost = kruskal.get_ost();
		cout << edges_ost.size() << endl;
		for (unsigned int i = 0; i < edges_ost.size(); ++i)
		{
			cout << edges_ost[i].getBegin().get_id() << "  " << edges_ost[i].getEnd().get_id() << endl;
		}
		cout << "-------------------------------------------------------------\nTESTS\n<------------------------------------------------------------\n";
		::testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
		system("pause");

	}
	else
	{
		cerr << "Error: cannot open file" << endl;
		system("pause");
	}
} 