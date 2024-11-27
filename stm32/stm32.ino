#include "stm32f7xx.h"

void UART2_Init(void) {
  // Enable the USART2 peripheral clock
  RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
  
  // Enable GPIOA peripheral clock
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

  // Configure PA2 (USART2_TX) as Alternate Function (AF7)
  GPIOA->MODER &= ~GPIO_MODER_MODER2;  // Clear PA2 mode
  GPIOA->MODER |= GPIO_MODER_MODER2_1; // Set PA2 to Alternate Function mode
  GPIOA->AFR[0] |= (7 << GPIO_AFRL_AFSEL2_Pos); // AF7 for USART2 TX

  // Configure PA3 (USART2_RX) as Alternate Function (AF7)
  GPIOA->MODER &= ~GPIO_MODER_MODER3;  // Clear PA3 mode
  GPIOA->MODER |= GPIO_MODER_MODER3_1; // Set PA3 to Alternate Function mode
  GPIOA->AFR[0] |= (7 << GPIO_AFRL_AFSEL3_Pos); // AF7 for USART2 RX

  // Configure USART2 settings (115200 baud rate, 8 data bits, 1 stop bit, no parity)
  USART2->BRR = 0x1D4C;  // Baud rate 115200 (assuming 16 MHz PCLK)
  USART2->CR1 |= USART_CR1_TE; // Enable the transmitter
  USART2->CR1 |= USART_CR1_UE; // Enable USART2
}

void UART2_SendChar(char c) {
  while (!(USART2->ISR & USART_ISR_TXE)); // Wait for the TXE flag to be set (TX buffer empty)
  USART2->TDR = c;  // Write character to the transmit data register
}

void UART2_SendString(const char *str) {
  while (*str) {
    UART2_SendChar(*str++); // Send each character in the string
  }
}

void setup() {
  // Initialize UART2 for transmission
  UART2_Init();

  // Initialize PB7 as an output pin for the LED
  pinMode(PB7, OUTPUT);
}

void loop() {
  // Blink the LED connected to PB7
  digitalWrite(PB7, HIGH);  // Turn on the LED
  delay(1000);               // Wait for 1 second
  digitalWrite(PB7, LOW);   // Turn off the LED
  delay(1000);               // Wait for 1 second

  // Transmit the "Hello" string over USART2 (PA2 for TX)
  UART2_SendString("Hello via USART2\n"); // Send the string
}
