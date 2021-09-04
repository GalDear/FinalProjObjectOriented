#include "pch.h"
#include "Car.h"

Car::Car(Date d, CString typeOfFuel, bool gearType, CString type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument) : gear(gearType ? "Auto" : "Manual"), Instrument(type, InstrumentID, availableOrFaulty, yearOfCreate, kilometersPerInstrument,150)
{
	this->testDate = d;
	this->typeOfFuel = typeOfFuel;
}

Date Car::GetDate()
{
	return this->testDate;
}

CString Car::GetTypeOfFuel()
{
	return this->typeOfFuel;
}

void Car::SetDate(Date d)
{
	this->testDate = d;
}

void Car::SetTypeOfFuel(CString typeOfFuel)
{
	this->typeOfFuel = typeOfFuel;
}


