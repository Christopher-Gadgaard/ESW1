#include "production.h"
#include "HAL.h"

static int16_t lastVoltage;

int production_sum(int a, int b)
{
	return a + b;
}

void production_create()
{
	HAL_create(10);
}
void production_messureTemperature(uint8_t sensorNo)
{
	lastVoltage = HAL_getVoltage(12);
}
int8_t production_getTemperature(uint8_t sensorNo)
{
	return lastVoltage * 2;
}