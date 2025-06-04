#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define BUZZER_PIN 21 // Configuração do pino do buzzer
#define BUZZER_FREQUENCY 100 // Frequência do buzzer em Hz

/**
 * Inicializa o buzzer configurando o pino como saída de PWM.
 * @param pin Pino GPIO onde o buzzer está conectado.
 */
void pwm_init_buzzer(uint pin);

/**
 * Emite um beep no buzzer por um determinado período.
 * @param pin Pino GPIO onde o buzzer está conectado.
 * @param duration_ms Duração do beep em milissegundos.
 */
void beep(uint pin, uint duration_ms);

#endif // BUZZER_H