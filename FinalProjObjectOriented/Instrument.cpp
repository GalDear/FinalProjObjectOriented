#include "pch.h"
#include "Instrument.h"


Instrument::Instrument()
{
}

Instrument::Instrument(CString type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument, int speedLimit)
{
	this->type = type;
	this->InstrumentID = InstrumentID;
	this->status = availableOrFaulty;
	this->yearOfCreate = yearOfCreate;
	this->kilometers = kilometersPerInstrument;
	this->speedLimit = speedLimit;
	this->company = L"";
	this->price = 0;
}

Instrument::Instrument(const Instrument &i)
{
	this->type = i.type;
	this->InstrumentID = i.InstrumentID;
	this->status = i.status;
	this->yearOfCreate = i.yearOfCreate;
	this->kilometers =i. kilometers;
	this->speedLimit = i.speedLimit;
	this->company = i.company;
	this->price = i.price;
}

long Instrument::GetInstrumentID()
{
	return this->InstrumentID;
}

CString Instrument::GetType()
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

CString Instrument::GetManufacturer()
{
	return this->manufacturer;
}

CString Instrument::GetColor()
{
	return this->color;
}

double Instrument::getPrice()
{
	return this->price;
}

CString Instrument::GetOwner()
{
	return this->company;
}

void Instrument::SetSpeedLimit(int newSpeedLimit)
{
	this->speedLimit = newSpeedLimit;
}

void Instrument::SetStatus(bool newStatus)
{
	this->status = newStatus;
}

void Instrument::SetColor(CString newColor)
{
	this->color = newColor;
}



void Instrument::SetOwner(CString s)
{
	this->company = s;
}
void Instrument::addKilometers(int km)
{
	this->kilometers += km;
}

void Instrument::setPrice(double p)
{
	this->price = p;
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

void operator<<(CArchive & os, Instrument & i)
{

	os << i.type;
	os << i.InstrumentID;
	os << i.status;
	os << i.yearOfCreate;
	os << i.kilometers;
	os << i.speedLimit;
	/*
	os << i.price;
	os << i.speedLimit;
	os << i.InstrumentID;
	
	os << i.DateOfStart;
	os << i.status;
	os << i.numOberfPassengers;
	os << i.yearOfCreate;
	os << i.kilometers;
	*/
}

void operator>>(CArchive & is, Instrument &i)
{

	is >> i.type;
	is >> i.InstrumentID;
	is >> i.status;
	is >> i.yearOfCreate;
	is >> i.kilometers;
	is >> i.speedLimit;

	//is >> i.type;
	//is >> i.InstrumentID;
	//is >> i.status;
	//is >> i.yearOfCreate;
	//is >> i.kilometers;
	//is >> i.speedLimit;
/*
	is >> i.price;
	is >> i.speedLimit;
	is >> i.InstrumentID;
	
	is >> i.DateOfStart;
	is >> i.status;
	is >> i.numOberfPassengers;
	is >> i.yearOfCreate;
	is >> i.kilometers;
	*/
}



