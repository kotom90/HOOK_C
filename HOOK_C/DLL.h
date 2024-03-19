#ifndef _DLL_TUTORIAL_H_
#define _DLL_TUTORIAL_H_
#include <iostream>

#define DECLDIR __declspec(dllexport)
//#define DECLDIR __declspec(dllimport)

extern "C"
{
   DECLDIR int Add( int a, int b );
   DECLDIR void Function( void );
}

#endif
