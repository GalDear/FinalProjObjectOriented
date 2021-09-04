#pragma once
#include "TransportCompany.h"

class FlyCompany : public TransportCompany
{
private:
	list<Client> VipClients;
	list<Location> stations;
public:
	FlyCompany() { };
	FlyCompany(list<Location> stations, CString typeOfTransportation, double pricePerKM, CString BusinessName, long BusinessNumber, int YearOfEstablishment,
		CString BusinessMail = NULL, CString BusinessPhoneNumber = NULL, int Rating = 0);

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

