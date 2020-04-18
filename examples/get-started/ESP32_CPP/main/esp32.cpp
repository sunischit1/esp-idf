#include <esp_log.h>
#include <string>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

//---------------------------- GPIO Config ---------------//
#define BLINK_GPIO CONFIG_BLINK_GPIO
//--------------------------------------------------------//
static char tag[]="cpp_helloworld";
//------------ CPP Interface-----------------------------//
extern "C" {
	void app_main(void);
}
//-----------------------------------------------------//

//-------------- Blink Class -------------------------//
class Blynk {
public:
    void ConfigLed(gpio_num_t pin,gpio_mode_t mode){
            :: gpio_pad_select_gpio(pin);
            /* Set the GPIO as a push/pull output */
            :: gpio_set_direction(pin,mode);
    }
    void SetGpioLevel(gpio_num_t pin,uint32_t value){
        :: gpio_set_level(pin,value);
    }
    void SetDelay(const TickType_t value){
        :: vTaskDelay(value/portTICK_PERIOD_MS);
    }
};
//----------------------------------------------------//

void app_main(void)
{
	Blynk myled;
    myled.ConfigLed((gpio_num_t)BLINK_GPIO,GPIO_MODE_OUTPUT);
    ESP_LOGD(tag, "Hello1 %s", "debug1");
    while(1){
        myled.SetGpioLevel((gpio_num_t)BLINK_GPIO,1);
        ESP_LOGD(tag, "Hello2 %s", "debug2");
        myled.SetDelay(1000);
        ESP_LOGD(tag, "Hello3 %s", "debug3");
        myled.SetGpioLevel((gpio_num_t)BLINK_GPIO,0);
        myled.SetDelay(1000);
    }
}