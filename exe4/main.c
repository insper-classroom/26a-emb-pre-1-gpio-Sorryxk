#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN   = 28;
const int LED_R = 5;
const int LED_P = 8;
const int LED_B = 11;
const int LED_G = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

  gpio_init(LED_R);
  gpio_set_dir(LED_R, GPIO_OUT);
  gpio_init(LED_P);
  gpio_set_dir(LED_P, GPIO_OUT);
  gpio_init(LED_B);
  gpio_set_dir(LED_B, GPIO_OUT);
  gpio_init(LED_G);
  gpio_set_dir(LED_G, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN)) {
      while (!gpio_get(BTN)) {};

      gpio_put(LED_R, 1);
      sleep_ms(300);
      gpio_put(LED_R, 0);

      gpio_put(LED_P, 1);
      sleep_ms(300);
      gpio_put(LED_P, 0);

      gpio_put(LED_B, 1);
      sleep_ms(300);
      gpio_put(LED_B, 0);

      gpio_put(LED_G, 1);
      sleep_ms(300);
      gpio_put(LED_G, 0);
    }
  }
}
