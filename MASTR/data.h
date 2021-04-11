#pragma once

typedef struct data {

	char* date;
	float open, high, low, close;
	unsigned long volume;

}DATA, * P_DATA;

//PROTOTYPES
P_DATA createData(char[], float, float, float, float, unsigned long);