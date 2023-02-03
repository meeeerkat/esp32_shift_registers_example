#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "shift_register.h"





void app_main(void)
{
  shift_register_t sr;
  shift_register__init(&sr, 16, 17, 18, 8);

  // Bits [1,0] at 1, others at 0
  shift_register__send(&sr, 0x03);
}
