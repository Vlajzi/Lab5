#pragma once
#include "Element.h"

class Graf
{
public:
	Graf(int count,int potezi);
	~Graf();
	void GenNewPint();
	void Conect(int a, int b, int weight);

	int Kruskal();

	int Boruvka();
private:
	int max_size;
	int max_potegs;
	int E;
	int V;
	vector<Element*> root;
	vector<Poteg*> potezi;
};

