// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ALIVE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ALIVE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ALIVE_EXPORTS
#define ALIVE_API __declspec(dllexport)
#else
#define ALIVE_API __declspec(dllimport)
#endif

#include "../Flower_shop/Base_Factory.h"

extern "C" ALIVE_API Base_Factory* Init();
int GetInputNumber();
