#pragma once
#include "Instrument.h"
#include <iostream>

using namespace std;

class Car :public Instrument {
public:
	Car() {};
	Car(Date, string, bool, string , long , bool , int , int );
	
	Date GetDate();
	string GetTypeOfFuel();

	void SetDate(Date);
	void SetTypeOfFuel(string);

private:
	Date testDate;
	string typeOfFuel;
	const string gear;
};