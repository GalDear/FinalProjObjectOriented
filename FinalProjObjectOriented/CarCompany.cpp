#pragma once
#include "pch.h"
#include "CarCompany.h"

CarCompany::CarCompany(string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
	string BusinessMail , string BusinessPhoneNumber , int Rating ) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
		BusinessMail, BusinessPhoneNumber, Rating)
{
}
