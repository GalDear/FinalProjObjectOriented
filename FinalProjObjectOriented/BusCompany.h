#pragma once
#include "TransportCompany.h"


class BusCompany : public TransportCompany
{
private:
	list<Location> stations;
public:
	BusCompany() :TransportCompany(){};
	BusCompany(list<Location> stations,
		string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = NULL, int Rating = 0);

	int GetListSize();

	void AddLocation(Location);
	void RemoveLocation(Location);	

	void setStations(list<Location>);

	bool hasStation(Location);
	double Discount();
};
