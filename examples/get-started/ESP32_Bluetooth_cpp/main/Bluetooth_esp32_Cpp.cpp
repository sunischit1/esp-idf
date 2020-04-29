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
#include "BLEScan.h"
#include "BLEDevice.h"
//----------------------File Configuration ---------------------//
//! If you want to use FreeRTOS cpp file then eanbled this macro
#define FREERTOS_FILE   ENABLED
//----------------------Global----------------------------------//
using namespace std;
static const char LOG_TAG[] = "SampleScan";
static uint8_t Counter;
//------------ CPP Interface-----------------------------//
extern "C" {
	void app_main(void);
}

//-----------------------------------------------------//
Cpp_Uitil Debug;
FreeRTOS Delay;
//----------------------------------------------------//
//------------------Project Specific Class --------------//
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
	void onResult(BLEAdvertisedDevice advertisedDevice) {
		ESP_LOGD(LOG_TAG, "Advertised Device: %s", advertisedDevice.toString().c_str());
	}
};
//-------------------------------------------------------//

//---------------------- Main Cpp Function-----------------------------------//
void app_main() {
    Debug.log("BLE Started\n");
    BLEDevice::init("");
    Debug.log("BLE Scan Started\n");
    BLEScan* pBLEScan = BLEDevice::getScan();
	pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
	pBLEScan->setActiveScan(true);
	BLEScanResults scanResults = pBLEScan->start(30);
}


///////////////////////////////////////////////////////////////////////