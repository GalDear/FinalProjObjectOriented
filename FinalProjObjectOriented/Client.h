#pragma once

#include <iostream>
#include <string.h>
#include <list>

using namespace std;

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

	public:
		Client(CString, CString, CString, bool); // constructor
		Client() { };
		~Client() { };

		const CString getName();
		const CString getEmail();
		const CString getId();
		const bool getDiscount();

		void setDiscount(bool);

		friend void operator<<(CArchive& os, Client &c);
		friend void operator>>(CArchive& is, Client &c);
		friend bool operator== (const Client&, const Client&);
		void operator=(const Client&);
	};
