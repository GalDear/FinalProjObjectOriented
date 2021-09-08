#pragma once
#include <iostream>
#include<string.h>
#include "location.h"
#include <list>
using namespace std;

struct seat {
	int row;
	int number;
	bool availability;
public:
	friend void operator<<(CArchive& ar, seat s) { ar << s.row << s.number << s.availability; };
	friend void operator>>(CArchive& ar, seat s) { ar >> s.row >> s.number >> s.availability; };
};

class Date 
{
private:
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y) { day = d; month = m; year = y; };
	Date() { };
	Date( const Date &d) { day = d.day; month = d.month; year = d.year; };
	const int getDay() const { return day; };
	const int getMonth() const { return month; };
	const int getYear() const { return year; };
	friend bool operator==(const Date&, const Date&);
	friend void operator<<(CArchive& ar, Date d) { ar << d.day << d.month << d.year; };
	friend void operator>>(CArchive& ar, Date d) { ar >> d.day >> d.month >> d.year; };


};

using namespace std;

class Instrument {
public:
	Instrument();
	Instrument(CString, long ,bool ,int ,int, int);
	Instrument(const Instrument &);
	~Instrument() {};

	// Gets
	long GetInstrumentID();
	CString GetType();
	int GetSpeedLimit();
	Date GetDateOfStart();
	bool GetStatus();
	int GetYearOfCreate();
	int GetKilometers();
	CString GetManufacturer();
	CString GetColor();
	int getNumOfSeats();
	double getPrice();
	CString GetOwner();

	// Sets
	void SetSpeedLimit(int newSpeedLimit);
	void SetStatus(bool newStatus);
	void SetColor(CString newColor);
	void addKilometers(int);
	void setPrice(double);
	void SetOwner(CString);

	friend bool operator==(const Instrument&, const Instrument&);

	virtual CString GetTypeOfGear() { return L""; };
	virtual CString GetTypeOfFuel() { return L""; };

	friend void operator<<(CArchive& os, Instrument &i);
	friend void operator>>(CArchive& is, Instrument &i);

	CString company;

private:
	CString type;
	long InstrumentID;
	int speedLimit;				// speed limit of the instrument
	Date DateOfStart;
	bool status;				// if the instrument available or need to be fixed
	int numOberfPassengers;
	int yearOfCreate;
	int kilometers;// how much kilometers the instrument can do
	CString manufacturer;
	CString color;
	double price;
	//CString company;
};