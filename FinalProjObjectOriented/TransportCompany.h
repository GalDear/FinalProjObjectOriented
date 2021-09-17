#pragma once
#include "Business.h"
#include "Location.h"


class TransportCompany :public Business {
private:
	CString typeOfTransportation;				// Rent, transportation, train, fly..
	list<Instrument*> availableInstruments;

	const double price;									//  per KM

public:
	TransportCompany();
	TransportCompany(CString typeOfTransportation,double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
		CString BusinessMail = NULL, CString BusinessPhoneNumber = 0, int Rating = 0);
	TransportCompany(const TransportCompany&);


	CString GetTypeOfTransportation();
	list<Instrument*> GetAvailableInstruments();

	double GetPrice();
	

	void SetTypeOfTransportation(CString);
	void addAvailableInstrument(Instrument&);


	double calcPrice(Location l1, Location l2);

	virtual bool hasStation(Location) { return false; };

	
};