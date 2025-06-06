#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

#include "globals.h"
#include "hardware/gpio.h"

/**
 * Inicializa o pino do sensor de chamas.
 */
void flame_sensor_init();

/**
 * Lê o estado do sensor de chamas.
 * @return true se chama detectada, false caso contrário.
 */
bool flame_detected();

#endif // FLAME_SENSOR_H
