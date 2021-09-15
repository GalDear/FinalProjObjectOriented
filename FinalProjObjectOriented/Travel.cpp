#include "pch.h"
#include "Travel.h"


IMPLEMENT_SERIAL(Travel, CObject,1)

Travel::Travel(Location source, Location destination, Instrument *instrument)
{
	this->source = source;
	this->destination = destination;
	this->instrument = instrument;
}


Travel::Travel(const Travel &t)
{
	this->source = t.source;
	this->destination = t.destination;
	this->instrument = t.instrument;
	this->numOfReservedSeats = t.numOfReservedSeats;
}


void Travel::Serialize(CArchive &ar)
{
	Instrument i;
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << source;
		ar << destination;
		i = *instrument;
		ar << i;
		ar << client;
	}
	else 
	{
		ar >> source;
		ar >> destination;
		this->instrument = new Instrument();
		ar >> *this->instrument;
		ar >> client;
	}
}

void Travel::attachClient(Client c)
{
	this->client = c;
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



double Travel::getTravelTime()
{
	return ((((this->source + this->destination) / this->instrument->GetSpeedLimit()) / 100 ) * 60);
}

double Travel::getTravelPrice()
{
	return ((this->destination + this->source)*this->instrument->getPrice());
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