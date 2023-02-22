#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "shift_register.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



void basic_test(shift_register_t* sr) {
  // Bits [1,0] at 1, others at 0
  shift_register__send(sr, 0x03);

  vTaskDelay(pdMS_TO_TICKS(1000));

  // Update the first 4 bits to 1110
  shift_register__update(sr, 0xF, 0xE);

  vTaskDelay(pdMS_TO_TICKS(1000));

  // Update the last 4 bits to 1010
  shift_register__update(sr, 0xF0, 0xA0);

  vTaskDelay(pdMS_TO_TICKS(1000));

  // All on
  shift_register__send(sr, 0xFF);

  vTaskDelay(pdMS_TO_TICKS(1000));

  // All off
  shift_register__send(sr, 0x0);
}


void counter(shift_register_t* sr) {
  for (uint16_t c=0; c < 256; c++) {
    shift_register__send(sr, c);
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}


void app_main()
{
  shift_register_t sr;
  shift_register__init(&sr, 16, 17, 18, 8);

  counter(&sr);
}
