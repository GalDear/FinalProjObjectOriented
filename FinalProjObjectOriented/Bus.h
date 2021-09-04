#pragma once
#include "Instrument.h"
#include <iostream>

using namespace std;
class Bus : public Instrument {
public:
	Bus() {};
	Bus(int, CString type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument);

	int GetLineNumber();

	void SetLineNumber(int);

private:
	int lineNumber;
};