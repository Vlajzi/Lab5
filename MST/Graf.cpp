#include"Graf.h"
#include <algorithm>
#include <iostream>
#include "Poteg.h"
#include "DisjointSets.h"

using namespace std;
Graf::Graf(int count,int potezi)
{
	max_size = count;
	max_potegs = potezi;
	V = 0;
	E = 0;
	
	
}

Graf::~Graf()
{
	//cout << "--Poziv Graf--"<<endl;
	
	vector<Element*>::iterator it2;
	for (it2 = root.begin(); it2 != root.end(); it2++)
	{
		(*it2)->~Element();
	}
	vector<Poteg*>::iterator it;
	for (it = potezi.begin(); it != potezi.end(); it++)
	{
		(*it)->~Poteg();
	}
}


void Graf::GenNewPint()
{
	if (V >= max_size)
	{
		return;
	}
	else
	{
		Element* tmp = new Element(V);
		root.push_back(tmp);
		V++;
	}
}

void Graf::Conect(int a, int b,int weight)
{
	if (E == max_potegs)
	{
		return;
	}
	E++;

	Poteg* tmp = new Poteg(root[a], root[b], weight);

	//root[a]->veze.push_back(tmp);
	potezi.push_back(tmp);

}

int Graf::Kruskal()
{
	

	int mst_wt = 0;
	std::sort(potezi.begin(),potezi.end(),Sort);


	DisjointSets ds(V);

	vector<Poteg*>::iterator it;
	for (it = potezi.begin(); it != potezi.end(); it++)
	{
		int u = (*it)->first->ind;
		int v = (*it)->second->ind;

		int set_u = ds.find(u);
		int set_v = ds.find(v);


		if (set_u != set_v)
		{
			if (V < 100)
			cout << u << " - " << v << endl;

			
			mst_wt += (*it)->tezina;

			
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;

	
}

int Graf::Boruvka()
{


	DisjointSets ds(V);


	int* cheapest = new int[V];

	for (int v = 0; v < V; ++v)
	{
		ds.parent[V] = v;
		ds.rnk[V] = 0;
		cheapest[v] = -1;
	}


	int numTrees = V;
	int MSTweight = 0;


	while (numTrees > 1)
	{
		for (int v = 0; v < V; ++v)
		{
			cheapest[v] = -1;
		}


		for (int i = 0; i < E; i++)
		{

			int set1 = ds.find( potezi[i]->first->ind);
			int set2 = ds.find( potezi[i]->second->ind);

			if (set1 == set2)
				continue;


			else
			{
				if (cheapest[set1] == -1 ||
					potezi[cheapest[set1]]->tezina > potezi[i]->tezina)
					cheapest[set1] = i;

				if (cheapest[set2] == -1 ||
					potezi[cheapest[set2]]->tezina > potezi[i]->tezina)
					cheapest[set2] = i;
			}
		}


		for (int i = 0; i < V; i++)
		{

			if (cheapest[i] != -1)
			{
				int set1 = ds.find(potezi[cheapest[i]]->first->ind);
				int set2 = ds.find(potezi[cheapest[i]]->second->ind);

				if (set1 == set2)
					continue;
				MSTweight += potezi[cheapest[i]]->tezina;
				if(V < 100)
				printf(" %d-%d \n",
					potezi[cheapest[i]]->first->ind, potezi[cheapest[i]]->second->ind);


				ds.merge(set1, set2);
				numTrees--;
			}
		}
	}

	
	return MSTweight;
}
