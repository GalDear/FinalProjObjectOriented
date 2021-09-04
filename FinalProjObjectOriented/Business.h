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
	Business(CString BusinessName, long BusinessNumber,int YearOfEstablishment,
		CString BusinessMail = NULL, CString BusinessPhoneNumber = 0 ,int Rating = 0);
	~Business();

	
	const CString GetBusinessName() const;
	const long GetBusinessNumber() const;
	const CString GetBusinessPhoneNumber() const;
	const CString GetBusinessMail() const;
	const int GetYearOfEstablishment() const;
	const int GetRating() const;

	
	void SetBusinessPhoneNumber(CString phoneNumber);
	void SetBusinessMail(CString email);
	void SetYearOfEstablishment(int number);
	void SetRating(int rate);

	virtual double Discount() = 0;

private:
	const CString BusinessName;
	long BusinessNumber;
	CString BusinessPhoneNumber;
	CString BusinessMail;
	int YearOfEstablishment;
	int Rating;						// 1-10 stars

};
