#include "pch.h"
#include "ScooterCompany.h"

ScooterCompany::ScooterCompany(CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
	CString BusinessMail, CString BusinessPhoneNumber, int Rating) :TransportCompany(typeOfTransportation, pricePerKM, BusinessName, BusinessNumber, YearOfEstablishment,
		BusinessMail, BusinessPhoneNumber, Rating)
{
}
double ScooterCompany::Discount()
{
	return GetPrice() * 0.95;
}
