#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "button.h"
#include "led.h"
#include "buzzer.h"
#include "flame_sensor.h" // Adicione este include

/**
 * @brief Inicializa periféricos: botão, LEDs, buzzer e sensor de chamas.
 */
void inicializa() {
    stdio_init_all();
    button_init();
    init_leds();
    pwm_init_buzzer(BUZZER_PIN);
    flame_sensor_init(); // Inicializa o sensor de chamas
}

/**
 * @brief Comportamento principal do programa.
 * Aciona o alerta quando o sensor de chamas detectar fogo.
 * Enquanto o sensor detectar chama, o alerta continuará sendo emitido.
 */
void comportamento_principal_sensor() {
    static bool alerta_ativo = false;
    if (flame_detected()) {
        red_led_on();
        buzzer_alert();
        printf("Chama detectada!\n");
        alerta_ativo = true;
    } else if (alerta_ativo) {
        red_led_off();
        buzzer_off(BUZZER_PIN);
        alerta_ativo = false;
    }
}

/**
 * @brief Função principal.
 */
int main() {
    inicializa();
    while (1) {
        comportamento_principal_sensor();
        sleep_ms(100);
    }
    return 0;
}
