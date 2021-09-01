#include "pch.h"
#include "Location.h"

Location::Location(string name, double distance,bool inIsrael)
{
	this->name = name.c_str();
	this->distance = distance;
	this->inIsrael = inIsrael;
}

void Location::setName(CString n)
{
	name = n;
}

void Location::setDistance(double d)
{
	distance = d;
}

CString Location::getName()
{
	return this->name;
}
double Location::getDistance()
{
	return this->distance;
}
bool Location::GetInIsrael()
{
	return this->inIsrael;
}
void Location::SetInIsrael(bool inIsrael)
{
	this->inIsrael = inIsrael;
}
bool operator== (const Location& l1, const Location&l2)
{
	if (l1.distance == l2.distance && l1.name == l2.name)
		return true;
	return false;
}
