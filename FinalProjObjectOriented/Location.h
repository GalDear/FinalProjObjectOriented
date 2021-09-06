#pragma once

#include <iostream>
#include<atlstr.h>
#include<string.h>
using namespace std;

/*
	Location with name and its distance from Tel-Aviv
*/
class Location
{
private:
	CString name;
	double distance; // Distance in KM from Tel-Aviv 
	bool inIsrael;

public:
	Location(string, double,bool);
	Location(const Location&);
	Location() { };
	CString getName();
	double getDistance();
	
	bool GetInIsrael();
	void SetInIsrael(bool);

	void setName(CString);
	void setDistance(double);

	friend bool operator== (const Location&, const Location&);
	friend double operator+(const Location&, const Location&);

	friend ostream& operator<<(ostream& os,Location &t);
	friend istream& operator>>(istream& is, Location &t);

};

