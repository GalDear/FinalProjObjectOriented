#include "pch.h"
#include "Travel.h"

Travel::Travel(Location source, Location destination, Instrument instrument)
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

const Location Travel::getSource()
{
	return this->source;
}

const Location Travel::getDestination()
{
	return this->destination;
}

Instrument Travel::getInstrument()
{
	return this->instrument;
}

list<seat> Travel::getReservedSeats()
{
	return this->instrument.GetSeats();
}

double Travel::getTravelTime()
{
	return ((this->source + this->destination) / this->instrument.GetSpeedLimit());
}

double Travel::getTravelPrice()
{
	return ((this->destination + this->source)*this->instrument.getPrice());
}

//const Date Travel::getDeparture()
//{
//	return this->departure;
//}

void Travel::changeInstrument(Instrument i)
{
	this->instrument = i;
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