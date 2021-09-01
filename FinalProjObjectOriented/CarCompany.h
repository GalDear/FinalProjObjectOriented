#pragma once
#include "TransportCompany.h"


class CarCompany : public TransportCompany
{
public:
	CarCompany() {};
	CarCompany(string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = NULL, int Rating = 0);

	double Discount() { return this->GetPrice(); };
};