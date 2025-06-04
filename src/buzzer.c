#include "buzzer.h"

void pwm_init_buzzer(uint pin) {
    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (BUZZER_FREQUENCY * 4096)); // Divisor de clock
    pwm_init(slice_num, &config, true);

    // Iniciar o PWM no nível baixo
    pwm_set_gpio_level(pin, 0);
}

void buzzer_off(uint pin) {
    // Desativar o sinal PWM (duty cycle 0)
    pwm_set_gpio_level(pin, 0);
}

void buzzer_on(uint pin) {
    // Ativar o sinal PWM com duty cycle de 50%
    pwm_set_gpio_level(pin, 2048); // 50% do duty cycle para um sinal audível
}

void buzzer_alert() {
    // Liga o buzzer
    buzzer_on(BUZZER_PIN);    
    sleep_ms(500);

    // Desliga o buzzer imediatamente
    buzzer_off(BUZZER_PIN);
    sleep_ms(500);
}