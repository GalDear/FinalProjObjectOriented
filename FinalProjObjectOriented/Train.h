#pragma once
#include "Instrument.h"
#include "Location.h"
#include <iostream>

using namespace std;

class Train :public Instrument {
public:
	Train() {};
	Train(Date, CString, CString, long , bool , int , int );

	Date GetDate();
	CString GetTypeOfFuel();

	void SetDate(Date);

private:
	Date testDate;
	CString type;			// electric or fuel
};