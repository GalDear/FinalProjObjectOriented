#include "pch.h"
#include "Plane.h"

Plane::Plane(Date testday, CString type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument) : Instrument(type, InstrumentID, availableOrFaulty, yearOfCreate, kilometersPerInstrument,700)
{
	this->testDate = testDate;
}

Date Plane::GetTestDate()
{
	return this->testDate;
}

void Plane::SetTestDate(Date d)
{
	this->testDate = d;
}