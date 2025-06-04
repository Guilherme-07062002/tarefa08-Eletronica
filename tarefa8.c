#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "button.h"
#include "led.h"
#include "buzzer.h"

/**
 * @brief Inicializa periféricos: UART, I2C, display OLED e botões.
 */
void inicializa() {
    stdio_init_all();
    button_init();
    init_leds();
    pwm_init_buzzer(BUZZER_PIN);
}

void toca_alerta() {
    beep(BUZZER_PIN, 500); // Toca o alerta por 500ms
    red_led_on(); // Acende o LED vermelho
}

/**
 * @brief Comportamento principal do programa.
 * Lê o valor da DIP switch ao pressionar o botão B e exibe no display e console.
 */
void comportamento_principal() {
    while (button_b_is_pressed()) {
        toca_alerta(); // Toca o alerta enquanto o botão B estiver pressionado
        printf("Botão B pressionado!\n");
    }
}

/**
 * @brief Função principal.
 */
int main() {
    inicializa();
    while (1) {
        comportamento_principal();
        sleep_ms(100);
    }
    return 0;
}
