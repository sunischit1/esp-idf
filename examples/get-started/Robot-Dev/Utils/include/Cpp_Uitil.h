/*
  @brief: This header file includes the cpp uitil class 
*/

//-------------------Header------------------------//
#include <stdint.h>
#include "freertos/FreeRTOS.h"
//----------------------------------------------//
#define TRUE    1
#define FALSE   0
#define ENABLED TRUE
#define DISABLED FALSE

//----------------------------------------------//
class Cpp_Uitil
{
private:
    /* data */
public:
    void log(const char* string,int arg1);
    void log(const char *string);
    void delay(TickType_t delayms);
};
