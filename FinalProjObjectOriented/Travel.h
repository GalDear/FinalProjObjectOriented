#pragma once
//#include "Location.h"
#include "Instrument.h"
#include "Client.h"
#include "TransportCompany.h"
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
	double travelPrice;

public:
	Travel(Location, Location, Instrument*);
	DECLARE_SERIAL(Travel)
	Travel(const Travel &);
	Travel() {};
	~Travel() {};
	

	void Serialize(CArchive&);
	void attachClient(Client *c);

	void setTravelPrice(TransportCompany*);
	
	Location getSource();
	Location getDestination();
	Instrument *getInstrument();
	Client getClient();

	double getTravelTime();
	const double getTravelPrice();


	friend bool operator==(const Travel&, const Travel&);
	void operator=(const Travel&);

};

