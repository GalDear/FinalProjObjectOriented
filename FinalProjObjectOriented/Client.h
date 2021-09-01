#pragma once

#include <iostream>
#include<string.h>
#include <list>

using namespace std;

#include "Travel.h"

	/*
		Details of client and his travel list
	*/
	class Client
	{
	private:
		CString name;
		CString id;
		CString email;
		bool discount;
		list<Travel> travels;

	public:
		Client(CString, CString, CString, bool); // constructor
		~Client() { };

		const CString getName();
		const CString getEmail();
		const CString getId();
		const bool getDiscount();
		const list<Travel> getTravels();

		void appendTravel(Travel);
		void setDiscount(bool);

		friend bool operator== (const Client&, const Client&);
	};
