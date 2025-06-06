#include "flame_sensor.h"

void flame_sensor_init() {
    gpio_init(FLAME_SENSOR_PIN);
    gpio_set_dir(FLAME_SENSOR_PIN, GPIO_IN);
    gpio_pull_down(FLAME_SENSOR_PIN); // Use pull-down se necessário
}

bool flame_detected() {
    // O sensor ativa nível alto quando chama detectada
    return gpio_get(FLAME_SENSOR_PIN) == 1;
}
