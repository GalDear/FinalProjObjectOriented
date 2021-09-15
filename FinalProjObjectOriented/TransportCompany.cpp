#include "pch.h"
#include "TransportCompany.h"



TransportCompany::TransportCompany():price(0)
{
}

TransportCompany::TransportCompany(CString typeOfTransportation, double pricePerKM
	, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
	CString BusinessMail , CString BusinessPhoneNumber , int Rating ) : price(pricePerKM),Business(BusinessName, BusinessNumber, YearOfEstablishment,
		 BusinessMail, BusinessPhoneNumber , Rating )
{
	this->typeOfTransportation = typeOfTransportation;
}

TransportCompany::TransportCompany(const TransportCompany &t) : price(t.price), Business(t.GetBusinessName(), t.GetBusinessNumber(), t.GetYearOfEstablishment(),
	t.GetBusinessMail(), t.GetBusinessPhoneNumber(), t.GetRating())
{
	this->typeOfTransportation = typeOfTransportation;
}

CString TransportCompany::GetTypeOfTransportation()
{
	return this->typeOfTransportation;
}

list<Instrument*> TransportCompany::GetAvailableInstruments()
{
	return this->availableInstruments;
}

list<Travel> TransportCompany::GetArrayOfAvailableTravels()
{
	return this->availableTravel;
}

int TransportCompany::GetPrice()
{
	return this->price;
}

void TransportCompany::SetTypeOfTransportation(CString typeOfTransportation)
{
	this->typeOfTransportation = typeOfTransportation;
}


void TransportCompany::addAvailableInstrument(Instrument &i)
{
	i.setPrice(this->price);
	i.SetOwner(this->GetBusinessName());
	this->availableInstruments.push_front(&i);
}

void TransportCompany::addTravel(Travel t)
{
	bool exist = false;
	list<Travel>::iterator iter;
	for (iter = this->availableTravel.begin(); iter != this->availableTravel.end(); ++iter)
	{
		if (*iter == t)
		{
			cout << "The Travel is already part of the travles list" << endl;
			exist = true;
			break;
		}
	}
	if (!exist)
	{
		availableTravel.push_front(t);
	}
}

double TransportCompany::calcPrice(Location l1, Location l2)
{
	return this->price*(l1.getDistance() + l2.getDistance());
}


