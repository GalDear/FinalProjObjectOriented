#include "pch.h"
#include "BusCompany.h"

BusCompany::BusCompany(list<Location> stations,
	CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
	CString BusinessMail , CString BusinessPhoneNumber , int Rating):TransportCompany( typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
BusinessMail , BusinessPhoneNumber , Rating )
{
	this->stations = stations;
}


bool BusCompany::hasStation(Location l)
{
	return std::find(stations.begin(), stations.end(), l) != stations.end();
}

double BusCompany::Discount()
{
	double price = this->GetPrice();
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

void BusCompany::setStations(list<Location> s)
{
	this->stations = s;
}

