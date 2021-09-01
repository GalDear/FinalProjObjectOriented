#include "pch.h"
#include "Company.h"

Company::Company(string typeOfTransportation, int p=0)
{
	this->typeOfTransportation = typeOfTransportation;
	this->totalInstruments = 0;
	this->price = p;
}

Company::~Company()
{
}


string Company::GetTypeOfTransportation()
{
	return this->typeOfTransportation;
}

list<Instrument> Company::GetAvailableInstruments()
{
	return this->availableInstruments;
}

list<Instrument> Company::GetNotAvailableInstruments()
{
	return this->unAvailableInstruments;
}

int Company::GetTotalInstruments()
{
	return this->totalInstruments;
}

list<Travel> Company::GetArrayOfAvailableTravels()
{
	return this->availableTravel;
}

int Company::GetPrice()
{
	return this->price;
}

void Company::SetTypeOfTransportation(string typeOfTransportation)
{
	this->typeOfTransportation = typeOfTransportation;
}


///////////////////////////////////////////////////////////////////
void Company::addAvailableInstrument(Instrument i)
{
	this->availableInstruments.push_front(i);
	this->totalInstruments++;
}

void Company::changeInstrumentStatus(Instrument i)
{
	list<Instrument>::iterator iter;
	for (iter = this->availableInstruments.begin(); iter != this->availableInstruments.end(); ++iter)
	{
		if (*iter == i)
		{
			iter->SetStatus(false);
			this->availableInstruments.erase(iter);
			this->unAvailableInstruments.push_front(i);
			break;
		}

	}
	
}


void Company::addTravel(Travel t)
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

void Company::updatePrice(int p)
{
	this->price = p > 0 ? p : this->price;
}
