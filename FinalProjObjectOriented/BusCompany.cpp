#include "pch.h"
#include "BusCompany.h"

BusCompany::BusCompany(list<Location> stations,
string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
string BusinessMail , string BusinessPhoneNumber , int Rating):TransportCompany( typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
BusinessMail , BusinessPhoneNumber , Rating )
{
	this->stations = stations;
}


double BusCompany::Discount()
{
	int price = this->GetPrice();
	return price * 0.90;
}

int BusCompany::GetListSize()
{
	return this->stations.size();
}

void BusCompany::AddLocation( Location city)
{
	this->stations.push_front(city);
}

void BusCompany::RemoveLocation(Location city) 
{	
	this->stations.remove(city);
}

