#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "shift_register.h"

static const char *TAG = "MAIN";

void app_main(void)
{
    init_shift_registers_handling();

    shift_register_t sr = shift_register__create(16, 17, 18, 8);
    shift_register__send(sr, 0xF0);
}
