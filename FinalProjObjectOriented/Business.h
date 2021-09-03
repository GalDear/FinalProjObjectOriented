#pragma once
#include <iostream>
#include <string>
#include <string>
#include "Instrument.h"
#include <list>
#include "Client.h"

using namespace std;

class Business {
public:
	Business() {};
	Business(string BusinessName, long BusinessNumber,int YearOfEstablishment,
		string BusinessMail = NULL, string BusinessPhoneNumber = 0 ,int Rating = 0);
	~Business();

	
	const string GetBusinessName() const;
	const long GetBusinessNumber() const;
	const string GetBusinessPhoneNumber() const;
	const string GetBusinessMail() const;
	const int GetYearOfEstablishment() const;
	const int GetRating() const;

	
	void SetBusinessPhoneNumber(string phoneNumber);
	void SetBusinessMail(string email);
	void SetYearOfEstablishment(int number);
	void SetRating(int rate);

	virtual double Discount() = 0;

private:
	const string BusinessName;
	long BusinessNumber;
	string BusinessPhoneNumber;
	string BusinessMail;
	int YearOfEstablishment;
	int Rating;						// 1-10 stars

};
