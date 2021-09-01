
// FinalProjObjectOriented.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"	// main symbols
#include "Bus.h"
#include "Car.h"
#include "Plane.h"
#include "Scooter.h"
#include "Train.h"

#include "BusCompany.h"
#include "CarCompany.h"
#include "FlyCompany.h"
#include "ScooterCompany.h"
#include "TrainCompany.h"

#include "Location.h"
#include "Travel.h"
#include "Client.h"




// CFinalProjObjectOrientedApp:
// See FinalProjObjectOriented.cpp for the implementation of this class
//

class CFinalProjObjectOrientedApp : public CWinApp
{
public:
	

	CFinalProjObjectOrientedApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFinalProjObjectOrientedApp theApp;
