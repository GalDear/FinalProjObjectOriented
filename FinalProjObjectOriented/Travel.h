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

	double getTravelTime();
	double getTravelPrice();


	friend bool operator==(const Travel&, const Travel&);
	void operator=(const Travel&);

};

