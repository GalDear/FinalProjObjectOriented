#include "pch.h"
#include "FlyCompany.h"

FlyCompany::FlyCompany( list<Location> stations, CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment
	, CString BusinessMail, CString BusinessPhoneNumber, int Rating) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
		BusinessMail, BusinessPhoneNumber, Rating)
{
	this->stations = stations;
}

bool FlyCompany::hasStation(Location l)
{
	bool b = std::find(stations.begin(), stations.end(), l) != stations.end();
	return b;
}

double FlyCompany::Discount()
{
	double price = this->GetPrice();
	return price * 0.90;
}

int FlyCompany::GetListSize()
{
	return this->stations.size();
}

int FlyCompany::GetVipClientsSize()
{
	return this->VipClients.size();
}

void FlyCompany::AddVipClient(Client c)
{
	this->VipClients.push_front(c);
}

void FlyCompany::RemoveVipClient(Client c)
{
	this->VipClients.remove(c);
}

void FlyCompany::AddLocation(Location city)
{
	this->stations.push_front(city);
}

void FlyCompany::RemoveLocation(Location city) {
	this->stations.remove(city);
}

void FlyCompany::setStations(list<Location> s)
{
	this->stations = s;
}
