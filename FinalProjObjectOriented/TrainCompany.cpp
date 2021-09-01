#include "pch.h"
#include "TrainCompany.h"


TrainCompany::TrainCompany(list<Location> stations,
	string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
	string BusinessMail, string BusinessPhoneNumber, int Rating) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
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

double TrainCompany::Discount()
{
	return GetPrice() * 0.85;
}