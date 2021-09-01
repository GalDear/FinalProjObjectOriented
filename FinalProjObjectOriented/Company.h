#pragma once
#include "Business.h"
#include "Location.h"
#include "Travel.h"
#include "list"

class Company :public Business {
private:
	string typeOfTransportation; 
	list<Instrument> availableInstruments;
	list<Instrument> unAvailableInstruments;
	int totalInstruments;
	list <Travel> availableTravel;
	int price;							//  per KM

public:
	Company() {};
	Company(string,int);
	~Company();

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
	void updatePrice(int);
	

};