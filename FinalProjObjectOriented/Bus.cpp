#include "pch.h"
#include "Bus.h"

Bus::Bus(int linenumber , string type, long InstrumentID, bool availableOrFaulty, int yearOfCreate, int kilometersPerInstrument) : Instrument(type, InstrumentID, availableOrFaulty, yearOfCreate, kilometersPerInstrument)
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