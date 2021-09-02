#include "pch.h"
#include "TransportCompany.h"



TransportCompany::TransportCompany():price(0)
{
}

TransportCompany::TransportCompany(string typeOfTransportation, double pricePerKM
	,string BusinessName, long BusinessNumber, int YearOfEstablishment,
	string BusinessMail , string BusinessPhoneNumber , int Rating ) : price(pricePerKM),Business(BusinessName, BusinessNumber, YearOfEstablishment,
		 BusinessMail, BusinessPhoneNumber , Rating )
{
	this->typeOfTransportation = typeOfTransportation;
	this->totalInstruments = 0;
}



string TransportCompany::GetTypeOfTransportation()
{
	return this->typeOfTransportation;
}

list<Instrument> TransportCompany::GetAvailableInstruments()
{
	return this->availableInstruments;
}

list<Instrument> TransportCompany::GetNotAvailableInstruments()
{
	return this->unAvailableInstruments;
}

int TransportCompany::GetTotalInstruments()
{
	return this->totalInstruments;
}

list<Travel> TransportCompany::GetArrayOfAvailableTravels()
{
	return this->availableTravel;
}

int TransportCompany::GetPrice()
{
	return this->price;
}

void TransportCompany::SetTypeOfTransportation(string typeOfTransportation)
{
	this->typeOfTransportation = typeOfTransportation;
}


void TransportCompany::addAvailableInstrument(Instrument i)
{
	this->availableInstruments.push_front(i);
	this->totalInstruments++;
}

void TransportCompany::changeInstrumentStatus(Instrument i)
{
	list<Instrument>::iterator iter;
	for (iter = this->availableInstruments.begin(); iter != this->availableInstruments.end(); ++iter)
	{
		if (*iter == i)
		{
			iter->SetStatus(!iter->GetStatus());
			this->availableInstruments.erase(iter);
			this->unAvailableInstruments.push_front(i);
			break;
		}

	}
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

