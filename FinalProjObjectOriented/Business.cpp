#include "pch.h"
#include "Business.h"

Business::Business(string BusinessName, long BusinessNumber, int YearOfEstablishment, string BusinessMail , string BusinessPhoneNumber , int Rating ) :BusinessName(BusinessName)
{
	this->BusinessNumber = BusinessNumber;
    this->BusinessPhoneNumber = BusinessPhoneNumber;
    this->BusinessMail = BusinessMail;
    this->YearOfEstablishment = YearOfEstablishment;
    this->Rating = Rating;
}

Business::~Business()
{
}

string Business::GetBusinessName()
{
    return this->BusinessName;
}

long Business::GetBusinessNumber()
{
    return this->BusinessNumber;
}

string Business::GetBusinessPhoneNumber()
{
    return this->BusinessPhoneNumber;
}

string Business::GetBusinessMail()
{
    return this->BusinessMail;
}

int Business::GetYearOfEstablishment()
{
    return this->YearOfEstablishment;
}

int Business::GetRating()
{
    return this->Rating;
}


void Business::SetBusinessPhoneNumber(string phoneNumber)
{
    this->BusinessPhoneNumber = phoneNumber;
}

void Business::SetBusinessMail(string email)
{
    this->BusinessMail = email;
}

void Business::SetYearOfEstablishment(int number)
{
    this->YearOfEstablishment = number;
}

void Business::SetRating(int rate)
{
    this->Rating = rate;
}


