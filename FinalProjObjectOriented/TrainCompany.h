#pragma once
#include "TransportCompany.h"

class TrainCompany:public TransportCompany
{
private:
	list<Location> stations;
public:
	TrainCompany() {};
	TrainCompany(list<Location> stations,
		string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = NULL, int Rating = 0);
	
	int GetListSize();

	void AddLocation(Location);
	void RemoveLocation(Location);
	double Discount();
};

