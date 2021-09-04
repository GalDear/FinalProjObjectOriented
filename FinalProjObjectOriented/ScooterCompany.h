#pragma once
#include "TransportCompany.h"

class ScooterCompany : public TransportCompany {
public:
	ScooterCompany() {};
	ScooterCompany(CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
		CString BusinessMail = NULL, CString BusinessPhoneNumber = NULL, int Rating = 0);

	double Discount();
};

