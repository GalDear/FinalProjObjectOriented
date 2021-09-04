#pragma once
#include "TransportCompany.h"

class FlyCompany : public TransportCompany
{
private:
	list<Client> VipClients;
	list<Location> stations;
public:
	FlyCompany() { };
	FlyCompany(list<Location> stations, string typeOfTransportation, double pricePerKM, string BusinessName, long BusinessNumber, int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = NULL, int Rating = 0);

	int GetListSize();
	int GetVipClientsSize();

	void AddVipClient(Client);
	void RemoveVipClient(Client);
	void AddLocation(Location);
	void RemoveLocation(Location);

	void setStations(list<Location>);

	bool hasStation(Location);
	double Discount();
};

