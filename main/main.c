#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "shift_register.h"

static const char *TAG = "MAIN";



shift_register_t sr;


void app_main(void)
{
    init_shift_registers_handling();


    shift_register__init(&sr, 16, 17, 18, 8);
    // Bits [7,4] at 1, others at 0
    shift_register__send(&sr, 0xF0);
}
