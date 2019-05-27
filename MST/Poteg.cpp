#include "Poteg.h"
#include "Element.h"

Poteg::Poteg()
{
	this->first = nullptr;
	this->second = nullptr;
	this->tezina = INT32_MAX;
}

Poteg::Poteg(Element* first, Element* second, int tezina)
{
	this->first = first;
	this->second = second;
	this->tezina = tezina;
}
 


