#pragma once
#include "TransportCompany.h"

class TrainCompany:public TransportCompany
{
private:
	list<Location> stations;
public:
	TrainCompany() {};
	TrainCompany(list<Location> stations,
		CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
		CString BusinessMail = NULL, CString BusinessPhoneNumber = NULL, int Rating = 0);
	
	int GetListSize();

	void AddLocation(Location);
	void RemoveLocation(Location);

	void setStations(list<Location>);

	bool hasStation(Location);

	double Discount();
};

