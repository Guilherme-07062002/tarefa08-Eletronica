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
 * Liga o buzzer, ativando o sinal PWM com duty cycle de 50%.
 * @param pin Pino GPIO onde o buzzer está conectado.
 */
void buzzer_on(uint pin);

/**
 * Desliga o buzzer, desativando o sinal PWM (duty cycle 0).
 * @param pin Pino GPIO onde o buzzer está conectado.
 */
void buzzer_off(uint pin);

/**
 * Emite um alerta sonoro com o buzzer.
 * Liga o buzzer por 1 segundo e depois desliga.
 */
void buzzer_alert();

#endif // BUZZER_H