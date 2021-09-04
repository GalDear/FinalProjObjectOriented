#pragma once
#include "Location.h"
#include "Instrument.h"

/*
	Travel from one location to another.
	Will contain the travel instrument, array of the reserved seats and departure Date.
*/

class Travel
{
private:
	Location source;
	Location destination;
	Instrument instrument;
	int numOfReservedSeats;
	//Date departure;

public:
	Travel(Location, Location, Instrument);
	Travel(const Travel &);
	~Travel() {};

	const Location getSource();
	const Location getDestination();
	const Instrument getInstrument();
	list<seat> getReservedSeats();
	//const Date getDeparture();

	double getTravelTime();
	double getTravelPrice();

	void changeInstrument(Instrument);
	void upDateReservedSeat(seat);
	//void UpDateDate(Date);

	friend bool operator==(const Travel&, const Travel&);

};

