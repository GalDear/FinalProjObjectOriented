#pragma once
#include "pch.h"
#include "CarCompany.h"

CarCompany::CarCompany(CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
	CString BusinessMail , CString BusinessPhoneNumber , int Rating ) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
		BusinessMail, BusinessPhoneNumber, Rating)
{
}
