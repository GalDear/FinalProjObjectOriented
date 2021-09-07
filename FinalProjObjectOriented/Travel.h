#pragma once
#include "Location.h"
#include "Instrument.h"
#include "Client.h"
#include <fstream>



/*
	Travel from one location to another.
	Will contain the travel instrument, array of the reserved seats and departure Date.
*/

class Travel : public CObject
{
private:
	
	
	Location source;
	Location destination;
	Instrument *instrument;
	int numOfReservedSeats;
	Client client;
	//Date departure;

public:
	Travel(Location, Location, Instrument*);
	DECLARE_SERIAL(Travel)
	Travel(const Travel &);
	Travel() {};
	~Travel() {};
	

	void Serialize(CArchive&);
	void attachClient(Client c);
	
	Location getSource();
	Location getDestination();
	Instrument *getInstrument();
	//const Date getDeparture();

	double getTravelTime();
	double getTravelPrice();

	void changeInstrument(Instrument*);
	void upDateReservedSeat(seat);
	//void UpDateDate(Date);

	friend bool operator==(const Travel&, const Travel&);

	/*friend ostream& operator<<(ostream& os, Travel &t);
	friend istream& operator>>(istream& is, Travel &t);*/

};

