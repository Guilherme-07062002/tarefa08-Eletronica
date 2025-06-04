#include "led.h"

void init_leds() {
    gpio_init(RED_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    gpio_init(BLUE_LED_PIN);

    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    gpio_put(RED_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(BLUE_LED_PIN, 0);
}

void red_led_on() {
    // Se já estiver aceso, não faz nada
    if (gpio_get(RED_LED_PIN)) return;

    // Apaga o LED verde e acende o LED vermelho
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(RED_LED_PIN, 1);
}

void green_led_on() {
    // Se já estiver aceso, não faz nada
    if (gpio_get(GREEN_LED_PIN)) return;

    // Apaga o LED vermelho e acende o LED verde
    gpio_put(RED_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 1);
}
