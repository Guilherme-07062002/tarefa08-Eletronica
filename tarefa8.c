#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "button.h"
#include "led.h"
#include "buzzer.h"

/**
 * @brief Inicializa periféricos: botão, LEDs e buzzer.
 */
void inicializa() {
    stdio_init_all();
    button_init();
    init_leds();
    pwm_init_buzzer(BUZZER_PIN);
}

/**
 * @brief Comportamento principal do programa.
 * Simula o comportamento do sensor de chamas, acionando o alerta quando o botão B é pressionado.
 * Enquanto o botão B estiver pressionado, o alerta continuará sendo emitido.
 */
void comportamento_principal_simulado() {
    static bool alerta_ativo = false;
    while (button_b_is_pressed()) {        
        red_led_on();
        buzzer_alert();
        printf("Botão B pressionado!\n");
        alerta_ativo = true;
    }
    if (button_b_is_pressed() == false && alerta_ativo) {
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
        comportamento_principal_simulado();
        sleep_ms(100);
    }
    return 0;
}
