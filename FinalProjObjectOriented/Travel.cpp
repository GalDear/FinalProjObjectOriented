#include "pch.h"
#include "Travel.h"


IMPLEMENT_SERIAL(Travel, CObject,1)

Travel::Travel(Location source, Location destination, Instrument *instrument)
{
	this->source = source;
	this->destination = destination;
	this->instrument = instrument;
	//this->departure = departure;
	numOfReservedSeats = 0;
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
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << source;
		ar << destination;
		ar << instrument;
		ar << numOfReservedSeats;
		ar << client;
	}
	else 
	{/*
		ar.Read(&source, sizeof(&source));
		ar.Read(&destination, sizeof(&destination));
		ar.Read(&instrument, sizeof(&instrument));*/
		ar >> source;
		ar >> destination;
		this->instrument = new Instrument();
		ar >> *instrument;
		ar >> numOfReservedSeats;
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
	return ((this->source + this->destination) / this->instrument->GetSpeedLimit());
}

double Travel::getTravelPrice()
{
	return ((this->destination + this->source)*this->instrument->getPrice());
}

//const Date Travel::getDeparture()
//{
//	return this->departure;
//}

void Travel::changeInstrument(Instrument *i)
{
	*this->instrument = *i;
}

void Travel::upDateReservedSeat(seat s)
{

}
//void Travel::UpDateDate(Date d)
//{
//	this->departure = d;
//}
bool operator==(const Travel &t1, const Travel &t2)
{
	if (/*t1.departure == t2.departure &&*/ t1.destination == t2.destination && t1.source == t2.source && t1.instrument == t2.instrument)
		return true;
	return false;
}

//ostream & operator<<(ostream & os, Travel & t)
//{
//	os << t.getSource;
//	os << t.getDestination;
//	os << t.getInstrument;
//	os << t.numOfReservedSeats;
//}
//
//istream & operator>>(istream & is, Travel & t)
//{
//	is >> t.source;
//	is >> t.destination;
//	is >> t.instrument;
//	is >> t.numOfReservedSeats;
//}
