#pragma once
#include "Business.h"
#include "Location.h"
#include "Travel.h"

class TransportCompany :public Business {
private:
	string typeOfTransportation;				// Rent, transportation, train, fly..
	list<Instrument> availableInstruments;
	list<Instrument> unAvailableInstruments;
	int totalInstruments;
	list <Travel> availableTravel;
	const double price;									//  per KM

public:
	TransportCompany();
	TransportCompany(string typeOfTransportation,double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = 0, int Rating = 0);

	string GetTypeOfTransportation();
	list<Instrument> GetAvailableInstruments();
	list<Instrument> GetNotAvailableInstruments();
	int GetTotalInstruments();
	list <Travel> GetArrayOfAvailableTravels();
	int GetPrice();
	

	void SetTypeOfTransportation(string);
	void addAvailableInstrument(Instrument);
	void changeInstrumentStatus(Instrument);
	void addTravel(Travel);

	double calcPrice(Location l1, Location l2);
	

};