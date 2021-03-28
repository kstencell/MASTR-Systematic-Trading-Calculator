#pragma once

#include "indicators.h"

typedef struct data {

	char* date;
	float open, high, low, close;
	unsigned long volume;

	P_INDICATORS indicators;

}DATA, * P_DATA;

//PROTOTYPES
P_DATA createData(char[], float, float, float, float, unsigned long);