#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

// asmsharp functions
extern void print_from_asmsharp();
//

void app_main(void) {
//  printf("Hello world!\n");
//  fflush(stdout);
//  vTaskDelay(1000 / portTICK_PERIOD_MS);
//  esp_restart();
  print_from_asmsharp();
}
