#include "pch.h"
#include "Scooter.h"

Scooter::Scooter(bool b, CString type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument) : Instrument(type, InstrumentID, availableOrFaulty, yearOfCreate, kilometersPerInstrument,10)
{
	this->helmet = b;
}

bool Scooter::GetHelmet()
{
	return this->helmet;
}

void Scooter::SetHelmet(bool b)
{
	this->helmet = b;
}
