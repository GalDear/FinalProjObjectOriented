#pragma once
#include "Instrument.h"
#include <iostream>

using namespace std;

class Scooter :public Instrument {
public:
	Scooter() {};
	Scooter(bool, string , long , bool , int , int );

	bool GetHelmet();

	void SetHelmet(bool);

private:
	bool helmet;
};