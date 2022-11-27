#pragma once
#include<stdint.h>

void HAL_create(uint8_t portNo);
int16_t HAL_getVoltage(uint8_t channel);