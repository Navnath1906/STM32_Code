#include "Arduino.h"

// Function to configure the USART1
void USART1_Init() {
    // Enable clock for GPIOA and USART1
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_USART1_CLK_ENABLE();

    // Configure PA9 as USART1 TX
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = GPIO_PIN_9; // PA9
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; // Alternate function, push-pull
    GPIO_InitStruct.Pull = GPIO_NOPULL; // No pull-up or pull-down resistors
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH; // Fast speed
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configure USART1 parameters
    USART_HandleTypeDef huart1;
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B; // 8 data bits
    huart1.Init.StopBits = UART_STOPBITS_1; // 1 stop bit
    huart1.Init.Parity = UART_PARITY_NONE; // No parity
    huart1.Init.Mode = UART_MODE_TX_ONLY; // TX only
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE; // No flow control
    huart1.Init.OverSampling = UART_OVERSAMPLING_16; // 16x oversampling

    // Initialize USART1
    if (HAL_UART_Init(&huart1) != HAL_OK) {
        // Initialization error
        Error_Handler();
    }
}

// Function to send data over USART1
void USART1_SendData(const char *data) {
    while (*data) {
        // Wait until USART1 TX is ready
        while (!(USART1->SR & USART_SR_TXE)) {}
        USART1->DR = (*data++); // Send data byte
    }
}

// Error handler function (can blink LED or enter infinite loop)
void Error_Handler(void) {
    while (1) {
        // Optional: Blink LED to indicate error
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Example LED on PA5
        HAL_Delay(500);
    }
}

void setup() {
    // Initialize USART1 for PA9 TX pin
    USART1_Init();

    // Send a test message
    USART1_SendData("Hello STM32F767!\n");
}

void loop() {
    // Send data continuously (every 1 second)
    USART1_SendData("Data sent via PA9 (USART1 TX)\n");
    delay(1000); // Wait for 1 second
}
