#include "pch.h"
#include "Bus.h"

Bus::Bus(int linenumber , CString type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument) : Instrument(type, InstrumentID, availableOrFaulty, yearOfCreate, kilometersPerInstrument, 100)
{
	this->lineNumber = lineNumber;
}

int Bus::GetLineNumber()
{
	return this->lineNumber;
}

void Bus::SetLineNumber(int lineNumber)
{
	this->lineNumber = lineNumber;
}