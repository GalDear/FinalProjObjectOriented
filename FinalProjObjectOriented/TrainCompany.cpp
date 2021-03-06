#include "pch.h"
#include "TrainCompany.h"


TrainCompany::TrainCompany(list<Location> stations,
	CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
	CString BusinessMail, CString BusinessPhoneNumber, int Rating) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
		BusinessMail, BusinessPhoneNumber, Rating)
{
	this->stations = stations;
}

int TrainCompany::GetListSize()
{
	return this->stations.size();
}

void TrainCompany::AddLocation(Location city)
{
	this->stations.push_front(city);
}

void TrainCompany::RemoveLocation(Location city) {
	this->stations.remove(city);
}

void TrainCompany::setStations(list<Location> s)
{
	this->stations = s;
}

bool TrainCompany::hasStation(Location l)
{
	bool b = std::find(stations.begin(), stations.end(), l) != stations.end();
	return b;
}

double TrainCompany::Discount()
{
	return GetPrice() * 0.85;
}