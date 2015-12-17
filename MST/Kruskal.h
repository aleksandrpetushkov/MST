#include "edge.h"
#include <vector>
#include <algorithm>    // std::sort



using namespace std;

class Kruskal
{
public:
	Kruskal() {}
	Kruskal(vector<edge>& _edges)
	{
		edges = _edges;
		sort(edges.begin(), edges.end()); // Сортеруем вектор, для этого в классе edges перегуржены операторы "<" "==" для сравнения.
		vector<int> listNodes;

		for (unsigned int i = 0; i < edges.size(); ++i)
		{
			bool b = false;
			bool e = false;
			for (unsigned int j = 0; j < listNodes.size(); ++j) //проверяем список узлов которые обошли на наличие узлов текущей ветви, если
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

			if (b&&e) // если оба узла имются в списке узлов возможно ветвь образует цикл, а может и нет - проверяем
			{
				vector<edge> tmp = edges_ost;
				vector<int> imp;
				bool rr = true;
				imp.push_back(edges[i].getEnd().get_id());
				while (tmp.size() != 0 && imp.size() != 0 && rr)
				{
					unsigned int zz = tmp.size();
					for (unsigned int z1 = 0; z1 < tmp.size(); ++z1)
					{
						if (*imp.begin() == tmp[z1].getBegin().get_id())
						{
							if (tmp[z1].getEnd().get_id() != edges[i].getBegin().get_id())
							{
								imp.push_back(tmp[z1].getEnd().get_id());
								tmp.erase(tmp.begin() + z1);
								--z1;
							}
							else
							{
								rr = false;
							}

						}
						else if (*imp.begin() == tmp[z1].getEnd().get_id())
						{
							if (tmp[z1].getBegin().get_id() != edges[i].getBegin().get_id())
							{
								imp.push_back(tmp[z1].getBegin().get_id());
								tmp.erase(tmp.begin() + z1);
								--z1;
							}
							else
							{
								rr = false;
							}
						}
					}
					imp.erase(imp.begin());
				}
				if (rr)
				{
					edges_ost.push_back(edges[i]);
				}
			}
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
		
	}
	unsigned int get_numberof_edges()
	{
		return  edges.size();
	}
	unsigned int get_numberof_edges_ost()
	{
		return edges_ost.size();
	}

	vector<edge> get_ost()
	{
		return edges_ost;
	}
protected:
	vector<edge> edges;
	vector<edge> edges_ost;
};