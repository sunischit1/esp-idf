//---------------- Incudes -------------------------------//
#include <esp_log.h>
#include <string>
#include <iostream>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"  // Free RTOS File
#include "freertos/task.h"
#include "driver/gpio.h"
#include "FreeRTOS.h" // CPP RTOS Lib Include
#include "Cpp_Uitil.h"
#include "Task.h"
//----------------------File Configuration ---------------------//
//! If you want to use FreeRTOS cpp file then eanbled this macro
#define FREERTOS_FILE   DISABLED
#define TASK_FILE       ENABLED
//----------------------Global----------------------------------//
using namespace std;
static char Tag[]="cpp_helloworld";
static uint8_t Counter;
//------------ CPP Interface-----------------------------//
extern "C" {
	void app_main(void);
}

//-----------------------------------------------------//
Cpp_Uitil Debug;
FreeRTOS ::Semaphore *semaphore = new FreeRTOS::Semaphore("SEMAPHORE");
FreeRTOS Delay;
//----------------------------------------------------//
#if(FREERTOS_FILE == ENABLED)
//------------------ Example Task1(For Counting Value)------------//
void (StartCounter)(void *arg)
{
 FreeRTOS *task1 = new FreeRTOS(); 
 uint32_t time;
 ESP_LOGD(Tag, "Hello1 %s", "Entered Task1"); 
  while(1)
  {
      Debug.log("Task 1 is Executing\n",1);
      Counter ++;
      semaphore->take("Task1");
      task1->sleep(1500);
      if(Counter >= 255)
      {
          time = task1->getTimeSinceStart();
          Debug.log("The time of run is %d: \n",(int)time);
          break;
      }
  }
}
//---------------------Example Task2(For Reading Counting Value)--------------//
void (ReadCounter)(void *arg)
{
    FreeRTOS *task2 = new FreeRTOS(); 
    while(1)
    {
        Debug.log("Task 2 is Executing\n",2);
        if(Counter <= 255)
        {
            Debug.log("The Value of Counter is %d: \n",Counter);
            task2->sleep(1500);
            semaphore->give();
        }
    }
}
//---------------------- Main Cpp Function-----------------------------------//
void app_main() {
	FreeRTOS *task = new FreeRTOS();
    TaskHandle_t taskno;
    task->startTask(StartCounter,"Counter",NULL,2048);
    taskno = task->GetTaskID();
    Debug.log("Task Value is %d: \n",(int)taskno);
    task->startTask(ReadCounter,"ReadCounter",NULL,2048);
    taskno = task->GetTaskID();
    Debug.log("Task Value is %d: \n",(int)taskno);
    ESP_LOGD(Tag, "Hello1 %s", "Task Started");
}
#endif
//////////////////////////////////////////////////////////////////////////
#if(TASK_FILE == ENABLED)
class Mytask1:public Task{
    void run(void * data)
    {
        while(1)
        {
            Debug.log("Running the Task1\n");
            Delay.sleep(5000);

        }
    }
};
class Mytask2:public Task{
    void run(void * data)
    {
        while(1)
        {
            Debug.log("Running the Task2\n");
            Delay.sleep(6000);

        }
    }
};
void app_main() {
	Mytask1 *task1 = new Mytask1();
    Mytask2 *task2 = new Mytask2();
    task1->setStackSize(2048);
    task2->setStackSize(2048);
    task1->setPriority(1);
    task2->setPriority(2);
    task1->start();
    task2->start();
}
#endif
///////////////////////////////////////////////////////////////////////