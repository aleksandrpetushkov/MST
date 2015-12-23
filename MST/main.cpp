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

	node n_tmp, n_tmp1;
	edge e_tmp;

	n_tmp.set(3, 9, 1);
	n_tmp1.set(7, 9, 3);
	e_tmp.set(n_tmp, n_tmp1);
	edges_ost_tst.push_back(e_tmp);

	n_tmp.set(3, 9, 1);
	n_tmp1.set(5, 13, 2);
	e_tmp.set(n_tmp, n_tmp1);
	edges_ost_tst.push_back(e_tmp);

	n_tmp.set(2, 3, 11);
	n_tmp1.set(4, 0, 15);
	e_tmp.set(n_tmp, n_tmp1);
	edges_ost_tst.push_back(e_tmp);

	n_tmp.set(4, 0, 15);
	n_tmp1.set(6, 5, 18);
	e_tmp.set(n_tmp, n_tmp1);
	edges_ost_tst.push_back(e_tmp);

	n_tmp.set(2, 3, 11);
	n_tmp1.set(7, 9, 3);
	e_tmp.set(n_tmp, n_tmp1);
	edges_ost_tst.push_back(e_tmp);

	n_tmp.set(1, 20, 30);
	n_tmp1.set(6, 5, 18);
	e_tmp.set(n_tmp, n_tmp1);
	edges_ost_tst.push_back(e_tmp);
	
	n_tmp.set_id(1);
	n_tmp.set_x(20);
	n_tmp.set_y(30);
	nodes.push_back(n_tmp);

	n_tmp.set_id(2);
	n_tmp.set_x(3);
	n_tmp.set_y(11);
	nodes.push_back(n_tmp);

	n_tmp.set_id(3);
	n_tmp.set_x(9);
	n_tmp.set_y(1);
	nodes.push_back(n_tmp);

	n_tmp.set_id(4);
	n_tmp.set_x(0);
	n_tmp.set_y(15);
	nodes.push_back(n_tmp);
	
	n_tmp.set_id(5);
	n_tmp.set_x(13);
	n_tmp.set_y(2);
	nodes.push_back(n_tmp);

	n_tmp.set_id(6);
	n_tmp.set_x(5);
	n_tmp.set_y(18);
	nodes.push_back(n_tmp);

	n_tmp.set_id(7);
	n_tmp.set_x(9);
	n_tmp.set_y(3);
	nodes.push_back(n_tmp);

	for (unsigned int j = 0; j < nodes.size() - 1; ++j)
	{
		edge tmp;
		for (unsigned int i = j + 1; i < nodes.size(); ++i)
		{
			tmp.set(nodes[j], nodes[i]);
			edges.push_back(tmp);
		}
	}
	Kruskal kruskal(edges);
	edges_ost = kruskal.get_ost();
	EXPECT_EQ(21, kruskal.get_numberof_edges());
	EXPECT_EQ(6, kruskal.get_numberof_edges_ost());
	for (unsigned int i = 0; i != 6; ++i)
	{
		EXPECT_EQ(edges_ost_tst[i], edges_ost[i]);
		EXPECT_EQ(edges_ost_tst[i].getBegin(), edges_ost[i].getBegin());
		EXPECT_EQ(edges_ost_tst[i].getEnd().get_x(), edges_ost[i].getEnd().get_x());
		EXPECT_EQ(edges_ost_tst[i].get_weight(), edges_ost[i].get_weight());
	}
}


int main(int argc, char* argv[])
{
	string name_in_file = "file.txt";
	ifstream fs(name_in_file, ios::in);
	if (fs)
	{
		vector<node> nodes;
		vector<edge> edges;
		vector<edge> edges_ost;


		while (!fs.eof())
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
		for (unsigned int i = 0; i < nodes.size(); ++i)
		{
			nodes[i].print();
		}
		//*/
		//загружаем ноды
		for (unsigned int j = 0; j < nodes.size() - 1; ++j)
		{
			edge tmp;
			for (unsigned int i = j + 1; i < nodes.size(); ++i)
			{
				tmp.set(nodes[j], nodes[i]);
				edges.push_back(tmp);
			}
		}
		Kruskal kruskal(edges);

		edges_ost = kruskal.get_ost();
		cout << edges_ost.size() << endl;
		for (unsigned int i = 0; i < edges_ost.size(); ++i)
		{
			cout << edges_ost[i].getBegin().get_id() << "  " << edges_ost[i].getEnd().get_id() << endl;
		}
		cout << "-------------------------------------------------------------\nTESTS\n------------------------------------------------------------\n";
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