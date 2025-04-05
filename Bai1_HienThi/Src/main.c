#include <stdint.h>
#include <system_stm32f4xx.h>
#include <timer.h>
#include <Ucglib.h>

static ucg_t ucg;

int main(void)
{
  SystemCoreClockUpdate();
  TimerInit();

  Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
  ucg_ClearScreen(&ucg);

  ucg_SetFont(&ucg, ucg_font_helvR08_tf);
  ucg_SetColor(&ucg, 0, 255, 255, 255);
  ucg_SetColor(&ucg, 1, 0, 0, 0);

  ucg_SetRotate180(&ucg);
  ucg_DrawString(&ucg, 40, 12, 0, "xin chao");
  ucg_DrawString(&ucg, 0, 26, 0, "nhom 5");

  while(1)
  {
    processTimerScheduler();
  }
}
