#pragma once
#include<stdio.h>
#include<stdint.h>

int production_sum(int a, int b);

void production_create();
void production_messureTemperature(uint8_t sensorNo);
int8_t production_getTemperature(uint8_t sensorNo);