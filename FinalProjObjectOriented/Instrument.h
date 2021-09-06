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

};

using namespace std;

class Instrument {
public:
	Instrument();
	Instrument(string , long ,bool ,int ,int);

	// Gets
	long GetInstrumentID();
	string GetType();
	int GetSpeedLimit();
	Date GetDateOfStart();
	bool GetStatus();
	list <seat> GetSeats();
	int GetYearOfCreate();
	int GetKilometers();
	string GetManufacturer();
	string GetColor();
	int getNumOfSeats();

	// Sets
	void SetSpeedLimit(int newSpeedLimit);
	void SetStatus(bool newStatus);
	void SetColor(string newColor);
	void SetSeats(int, int);
	void addKilometers(int);

	friend bool operator==(const Instrument&, const Instrument&);

	//friend ostream& operator<<(ostream& os, Instrument &t);
	//friend istream& operator>>(istream& is, Instrument &t);

private:
	string type;
	long InstrumentID;
	int speedLimit;				// speed limit of the instrument
	Date DateOfStart;
	bool status;				// if the instrument available or need to be fixed
	int numOberfPassengers;
	list <seat> seats;
	int yearOfCreate;
	int kilometers;// how much kilometers the instrument can do
	string manufacturer;		
	string color;
};