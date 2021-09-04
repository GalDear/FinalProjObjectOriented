#include "pch.h"
#include "Train.h"

Train::Train(Date testDate ,string fueltype, string type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument) : Instrument(type, InstrumentID, availableOrFaulty, yearOfCreate, kilometersPerInstrument,120)
{
	this->testDate = testDate;
	this->type = fueltype;
}
void Train::SetDate(Date d)
{
	this->testDate = d;
}

Date Train::GetDate()
{
	return this->testDate;
}

string Train::GetType()
{
	return this->type;
}
