#include "pch.h"
#include "Client.h"
 
Client::Client(CString name, CString id, CString email, bool discount = false)
{
	this->name = name;
	this->id = id;
	this->email = email;
	this->discount = discount;
}

const CString Client::getName()
{
	return this->name;
}

const CString Client::getEmail()
{
	return this->email;
}

const CString Client::getId()
{
	return this->id;
}

const bool Client::getDiscount()
{
	return this->discount;
}


void Client::setDiscount(bool b)
{
	this->discount = b;
}

void Client::operator=(const Client &c)
{
	this->name = c.name;
	this->email = c.email;
	this->id = c.id;
	this->discount = c.discount;
}

void operator<<(CArchive & os, Client & c)
{
	os << c.name << c.id << c.email << c.discount;
}

void operator>>(CArchive & is, Client & c)
{
	is >> c.name >> c.id >> c.email >> c.discount;
}

bool operator== (const Client& l1, const Client&l2)
{
	if (l1.email == l2.email && l1.id == l2.id && l1.email == l2.email)
		return true;
	return false;
}