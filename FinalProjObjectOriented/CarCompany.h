#pragma once
#include "TransportCompany.h"


class CarCompany : public TransportCompany
{
public:
	CarCompany() {};
	CarCompany(CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
		CString BusinessMail = NULL, CString BusinessPhoneNumber = NULL, int Rating = 0);

	double Discount() { return this->GetPrice(); };
};