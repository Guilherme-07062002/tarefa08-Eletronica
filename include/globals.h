#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * Indica se um programa está em execução.
 */
extern bool program_running;

#define FLAME_SENSOR_PIN 8 // GPIO utilizado para ler o sensor de chamas

#endif // GLOBALS_H