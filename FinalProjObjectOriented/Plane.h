#pragma once
#include "Instrument.h"
#include <iostream>

using namespace std;

class Plane :public Instrument {
public:
	Plane() {};
	Plane(Date, CString, long , bool , int , int );

	Date GetTestDate();

	void SetTestDate(Date);

private:
	Date testDate;		// Date of test
};