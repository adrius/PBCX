// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PBCX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PBCX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PBCX_EXPORTS
#define PBCX_API __declspec(dllexport)
#else
#define PBCX_API __declspec(dllimport)
#endif

#define PBCALL __stdcall

// This class is exported from the PBCX.dll
class PBCX_API CPBCX {
public:
	CPBCX(void);
	// TODO: add your methods here.
};

extern PBCX_API int nPBCX;

PBCX_API int PBCALL fnPBCX(void);
