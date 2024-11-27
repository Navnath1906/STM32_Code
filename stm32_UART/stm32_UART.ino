#include "stm32f7xx_hal.h"

// Function to initialize all GPIOs
void GPIO_Init_All(void) {
    // Enable clocks for all GPIO ports (A, B, C, D, E, F, G, H, I)
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();

    // GPIO configuration structure
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Push-pull output mode
    GPIO_InitStruct.Pull = GPIO_NOPULL;          // No pull-up or pull-down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Low speed

    // Initialize all pins on each port as output
    GPIO_InitStruct.Pin = GPIO_PIN_All;  // All pins

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
}

// Function to set all GPIO pins high
void GPIO_Set_All_High(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_All, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOI, GPIO_PIN_All, GPIO_PIN_SET);
}

// Function to set all GPIO pins low
void GPIO_Set_All_Low(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_All, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOI, GPIO_PIN_All, GPIO_PIN_RESET);
}

int main(void) {
    HAL_Init();  // Initialize the HAL Library
    SystemClock_Config();  // Configure the system clock if necessary

    // Initialize all GPIOs as outputs
    GPIO_Init_All();

    while (1) {
        // Set all GPIOs high, wait for 1 second
        GPIO_Set_All_High();
        HAL_Delay(1000);  // 1000 ms delay

        // Set all GPIOs low, wait for 1 second
        GPIO_Set_All_Low();
        HAL_Delay(1000);  // 1000 ms delay
    }
}
