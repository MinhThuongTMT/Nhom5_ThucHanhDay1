#include <stdio.h>
#include <stdint.h>
#include <stm32f401re.h>
#include <stm32f401re_rcc.h>
#include <stm32f401re_gpio.h>

#define LED_GPIO_PORT GPIOA
#define LED_GPIO_PIN GPIO_Pin_0
#define LEDControl_SetClock RCC_AHB1Periph_GPIOA

static uint32_t globalVariable = 0;

static void mainInit();
static void led_Init(void);
static void ButtonB2_Init(void);
void watchLocalVariable();

int main(void)
{
    mainInit();
    watchLocalVariable();

    while(1)
    {
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3) == 0)
        {
            GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);
        }
        else
        {
            GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN);
        }
    }
}

static void mainInit()
{
    SystemCoreClockUpdate();
    ButtonB2_Init();
    led_Init();
}

void watchLocalVariable()
{
    uint8_t localVariable = 0;
    globalVariable = localVariable + 1;
    localVariable = globalVariable + 1;
}

static void ButtonB2_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

static void led_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(LEDControl_SetClock, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;

    GPIO_Init(LED_GPIO_PORT, &GPIO_InitStructure);
}
