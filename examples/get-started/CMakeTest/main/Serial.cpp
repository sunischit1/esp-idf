#include <esp_log.h>
#include <string>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "Cpp_Uitil.h"
//---------------------------- GPIO Config ---------------//
#define BLINK_GPIO CONFIG_BLINK_GPIO
//--------------------------------------------------------//
static char tag[]="cpp_helloworld";
Cpp_Uitil Debug;
//------------ CPP Interface-----------------------------//
extern "C" {
	void app_main(void);
}
//-----------------------------------------------------//


//----------------------------------------------------//

void app_main(void)
{
    
    while(1)
    {
        ESP_LOGD(tag, "Hello1 %s", "debug1");
        Debug.delay(1000);
    }
}