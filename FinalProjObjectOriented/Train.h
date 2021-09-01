#pragma once
#include "Instrument.h"
#include "Location.h"
#include <iostream>

using namespace std;

class Train :public Instrument {
public:
	Train() {};
	Train(Date, string, string , long , bool , int , int );

	Date GetDate();
	string GetType();

	void SetDate(Date);

private:
	Date testDate;
	string type;			// electric or fuel
};