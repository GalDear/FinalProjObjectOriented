#pragma once
#include "TransportCompany.h"

class ScooterCompany : public TransportCompany {
public:
	ScooterCompany() {};
	ScooterCompany(string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = NULL, int Rating = 0);

	double Discount();
};

