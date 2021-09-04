#include "pch.h"
#include "Business.h"

Business::Business(const CString BusinessName, long BusinessNumber, int YearOfEstablishment, CString BusinessMail , CString BusinessPhoneNumber , int Rating ) :BusinessName(BusinessName)
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

const CString Business::GetBusinessName() const
{
    return this->BusinessName;
}

const long Business::GetBusinessNumber() const
{
    return this->BusinessNumber;
}

const CString Business::GetBusinessPhoneNumber() const
{
    return this->BusinessPhoneNumber;
}

const CString Business::GetBusinessMail() const
{
    return this->BusinessMail;
}

const int Business::GetYearOfEstablishment() const
{
    return this->YearOfEstablishment;
}

const int Business::GetRating() const
{
    return this->Rating;
}


void Business::SetBusinessPhoneNumber(CString phoneNumber)
{
    this->BusinessPhoneNumber = phoneNumber;
}

void Business::SetBusinessMail(CString email)
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


