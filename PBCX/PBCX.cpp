// PBCX.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PBCX.h"


// This is an example of an exported variable
PBCX_API int nPBCX=0;

// This is an example of an exported function.
PBCX_API int fnPBCX(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see PBCX.h for the class definition
CPBCX::CPBCX()
{
	return;
}
