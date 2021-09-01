#include "pch.h"
#include "ScooterCompany.h"

ScooterCompany::ScooterCompany(string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
	string BusinessMail, string BusinessPhoneNumber, int Rating) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
		BusinessMail, BusinessPhoneNumber, Rating)
{
}
double ScooterCompany::Discount()
{
	return GetPrice() * 0.95;
}
