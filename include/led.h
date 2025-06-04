#ifndef LED_H
#define LED_H

#include "hardware/gpio.h" // Inclui o cabeçalho para funções GPIO

#define BLUE_LED_PIN 12 // Definição do pino do LED azul
#define RED_LED_PIN 13 // Definição do pino do LED vermelho
#define GREEN_LED_PIN 11 // Definição do pino do LED verde

/**
 * @brief Inicializa os LEDs configurando os pinos como saídas.
 */
void init_leds();

/**
 * @brief Acende o LED vermelho e apaga o LED verde.
 */
void red_led_on();

/**
 * @brief Apaga o LED vermelho.
 */
void red_led_off();

/**
 * @brief Acende o LED verde e apaga o LED vermelho.
 */
void green_led_on();

/**
 * @brief Apaga o LED verde.
 */
void green_led_off();

#endif // LED_H
