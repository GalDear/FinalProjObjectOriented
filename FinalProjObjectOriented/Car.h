#pragma once
#include "Instrument.h"
#include <iostream>

using namespace std;

class Car :public Instrument {
public:
	Car() {};
	Car(Date, CString, bool, CString, long , bool , int , int );
	
	Date GetDate();
	CString GetTypeOfFuel() override;
	CString GetTypeOfGear() override;

	void SetDate(Date);
	void SetTypeOfFuel(CString);

private:
	Date testDate;
	CString typeOfFuel;
	const CString gear;
};