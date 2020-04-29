/*
@brief: This file includes all the definition for Cpp_uitils
*/

//-----------------------Header------------------------------//
#include<stdint.h>
#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Cpp_Uitil.h"
using namespace std;

//----------------Function Definition -------------------------//
/*
@brief: Definition for print
@pram1: string name
@pram2: int value
*/
void Cpp_Uitil::log(const char* string,int arg1)
{
    ::printf(string,arg1);
}
/*
@brief: Definition for print
@pram1: string name
*/
 void Cpp_Uitil:: log(const char *string)
 {
     ::printf(string);
 }
 /*
  * @brief: Delay Function
  * 
  */
  void Cpp_Uitil::delay(TickType_t delayms)
  {
      ::vTaskDelay(delayms/portTICK_PERIOD_MS);
  }