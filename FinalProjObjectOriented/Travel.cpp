#include "pch.h"
#include "Travel.h"


IMPLEMENT_SERIAL(Travel, CObject,1)

Travel::Travel(Location source, Location destination, Instrument *instrument)
{
	this->source = source;
	this->destination = destination;
	this->instrument = instrument;
	this->travelPrice = 0;
}


Travel::Travel(const Travel &t)
{
	this->source = t.source;
	this->destination = t.destination;
	this->instrument = t.instrument;
	this->travelPrice = t.travelPrice;
	this->client = t.client;
}


void Travel::Serialize(CArchive &ar)
{
	Instrument i;
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << source;
		ar << destination;
		ar << travelPrice;
		i = *instrument;
		ar << i;
		ar << client;
	}
	else 
	{
		ar >> source;
		ar >> destination;
		ar >> travelPrice;
		this->instrument = new Instrument();
		ar >> *this->instrument;
		ar >> client;
	}
}

void Travel::attachClient(Client *c)
{
	this->client = *c;
}

Location Travel::getSource()
{
	return this->source;
}

Location Travel::getDestination()
{
	return this->destination;
}

Instrument *Travel::getInstrument()
{
	return this->instrument;
}

Client Travel::getClient()
{
	return this->client;
}



double Travel::getTravelTime()
{
	return ((((this->source + this->destination) / this->instrument->GetSpeedLimit()) / 100 ) * 60);
}

const double Travel::getTravelPrice()
{
	return this->travelPrice;
}

void Travel::setTravelPrice(TransportCompany* comp)
{
	double d = comp->Discount();
	double p = comp->GetPrice();
	if(client.getDiscount())
		this->travelPrice = ((this->destination + this->source)*d);
	else
		this->travelPrice = ((this->destination + this->source)*p);
}



void Travel::operator=(const Travel &t)
{
	this->source = t.source;
	this->destination = t.destination;
	this->instrument = t.instrument;
	this->numOfReservedSeats = t.numOfReservedSeats;
}

bool operator==(const Travel &t1, const Travel &t2)
{
	if ( t1.destination == t2.destination && t1.source == t2.source && t1.instrument == t2.instrument)
		return true;
	return false;
}