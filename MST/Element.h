#pragma once

#include <vector>

class Poteg;

using namespace std;

class Element
{
public:
	Element(int ind);
	~Element() = default;
	void AddPoteg(Poteg* a);

	int ind;
	//vector<Poteg*> veze;
};
