#pragma once
#include "Business.h"
#include "Location.h"
#include "Travel.h"

class TransportCompany :public Business {
private:
	string typeOfTransportation;				// Rent, transportation, train, fly..
	list<Instrument> availableInstruments;
	list<Instrument> unAvailableInstruments;
	list <Travel> availableTravel;
	const double price;									//  per KM

public:
	TransportCompany();
	TransportCompany(string typeOfTransportation,double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = 0, int Rating = 0);
	TransportCompany(const TransportCompany&);


	string GetTypeOfTransportation();
	list<Instrument> GetAvailableInstruments();
	list<Instrument> GetNotAvailableInstruments();
	list <Travel> GetArrayOfAvailableTravels();
	int GetPrice();
	

	void SetTypeOfTransportation(string);
	void addAvailableInstrument(Instrument);
	void changeInstrumentStatus(Instrument);
	void addTravel(Travel);

	double calcPrice(Location l1, Location l2);

	virtual bool hasStation(Location) { return false; };
	
};