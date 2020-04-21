/*
@brief: This file includes all the definition for Cpp_uitils
*/

//-----------------------Header------------------------------//
#include<stdint.h>
#include<stdio.h>
#include "Cpp_Uitil.h"
using namespace std;

//----------------Function Definition -------------------------//
/*
@brief: Definition for print
@pram1: string name
@pram2: Optional int value
@pram3: Optional string value
*/
void Cpp_Uitil::log(const char* string,int arg1)
{
    ::printf(string,arg1);
}