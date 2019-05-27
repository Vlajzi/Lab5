#include "Element.h"
#include "Poteg.h"
#include <iostream>

using namespace std;
Element::Element(int ind)
{
	this->ind = ind;
}

/*Element::~Element()
{
	//cout << "--Poziv Elm--" <<endl;

	//veze.~vector<Poteg*>();
}*/

void Element::AddPoteg(Poteg* a)
{
	//this->veze.push_back(a);
}

