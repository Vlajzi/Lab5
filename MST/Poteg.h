#pragma once



class Element;

class Poteg
{
public:
	Poteg();
	Poteg(Element* first, Element* second, int tezina);
	~Poteg() = default;
	

	Element* first,*second;
	int tezina;


};
static bool Sort(Poteg* a,Poteg* b);

static bool Sort(Poteg* a, Poteg* b)
{
	return (a->tezina < b->tezina);

}