/*
 * 
 * Comunicação serial com I2C
 *  
 * Uso da interface I2C para comunicação com o Display OLED
 * 
 * Estudo da biblioteca ssd1306 com PicoW na Placa BitDogLab.
 *  
 * Este programa escreve uma mensagem no display OLED.
 * 
 * Código baseado em material do github produzido por: Wilton Lacerda Silva
*/


#include <stdlib.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "pico/time.h" // <<< 1. INCLUÍDO para usar funções de tempo
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C


#define VRX_PIN 27      // GPIO para eixo X
#define SERVO_GPIO 20
#define SERVO_MIN_US 0   // Posição de 0 graus
#define SERVO_MAX_US 3.3  // Posição de 180 graus









int main()
{
     stdio_init_all();

     adc_init();
     adc_gpio_init(VRX_PIN);
     adc_select_input(1);

     // I2C Initialisation. Using it at 400Khz.
     i2c_init(I2C_PORT, 400 * 1000);

     gpio_set_function(I2C_SDA, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
     gpio_set_function(I2C_SCL, GPIO_FUNC_I2C); // Set the GPIO pin function to I2C
     gpio_pull_up(I2C_SDA); // Pull up the data line
     gpio_pull_up(I2C_SCL); // Pull up the clock line
     ssd1306_t ssd; // Inicializa a estrutura do display
     ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
     ssd1306_config(&ssd); // Configura o display
     ssd1306_send_data(&ssd); // Envia os dados para o display
     ssd1306_fill(&ssd, false); // Limpa o display. O display inicia com todos os pixels apagados.
     ssd1306_send_data(&ssd);

     bool cor = true;
     char adc_text[15];

   while (true) {
        // 1. LER a posição do joystick
         uint16_t adc_x = adc_read();

        // 2. TRADUZIR a leitura do ADC para valores de tensão
        float tensao = (adc_x / 4095.0f) * 3.3f;

        printf("TENSÃO: %d", adc_x);
        sprintf(adc_text, "%.2f V", tensao);

        ssd1306_fill(&ssd, !cor); // Limpa o display
        ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
        ssd1306_draw_string(&ssd, "TENSAO", 40, 16); 
        ssd1306_draw_string(&ssd, adc_text, 40, 40); 
        ssd1306_pixel(&ssd, 50, 47, 1);
        ssd1306_send_data(&ssd);
        

    sleep_ms(100);}
  }
