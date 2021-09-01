#include "pch.h"
#include "Instrument.h"


Instrument::Instrument()
{
}

Instrument::Instrument(string type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument)
{
	this->type = type;
	this->InstrumentID = InstrumentID;
	this->status = availableOrFaulty;
	this->yearOfCreate = yearOfCreate;
	this->kilometers = kilometersPerInstrument;
}

long Instrument::GetInstrumentID()
{
	return this->InstrumentID;
}

string Instrument::GetType()
{
	return this->type;
}

int Instrument::GetSpeedLimit()
{
	return this->speedLimit;
}

Date Instrument::GetDateOfStart()
{
	return this->DateOfStart;
}

bool Instrument::GetStatus()
{
	return this->status;
}

list <seat> Instrument::GetSeats()
{
	return this->seats;
}

int Instrument::GetYearOfCreate()
{
	return this->yearOfCreate;
}

int Instrument::GetKilometers()
{
	return this->kilometers;
}

int Instrument::getNumOfSeats()
{
	return this->numOberfPassengers;
}

string Instrument::GetManufacturer()
{
	return this->manufacturer;
}

string Instrument::GetColor()
{
	return this->color;
}

void Instrument::SetSpeedLimit(int newSpeedLimit)
{
	this->speedLimit = newSpeedLimit;
}

void Instrument::SetStatus(bool newStatus)
{
	this->status = newStatus;
}

void Instrument::SetColor(string newColor)
{
	this->color = newColor;
}
void Instrument::SetSeats(int rows, int cols)
{
	for (int i = 1; i <= rows; i++)
	{
		for (int j=1 ; j <= cols; j++)
		{
			seat s;
			s.row = i;
			s.number = j;
			s.availability = true;
			this->seats.push_front(s);
		}
	}
}
void Instrument::addKilometers(int km)
{
	this->kilometers += km;
}

bool operator==(const Date &d1, const Date &d2)
{
	if (d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear())
		return true;
	return false;
}
bool operator==(const Instrument &i1, const Instrument &i2)
{
	if (i1.InstrumentID == i2.InstrumentID)
		return true;
	return false;
}

