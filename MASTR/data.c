
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"
#include "indicators.h"

P_DATA createData(char date[], float open, float high, float low, float close, unsigned long volume) {

	P_DATA newData = (P_DATA)malloc(sizeof(DATA));
	if (!newData) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	newData->date = (char*)malloc(sizeof(char)*10);
	strcpy(newData->date, date);
	newData->open = open;
	newData->high = high;
	newData->low = low;
	newData->close = close;
	newData->volume = volume;

	newData->indicators = createIndicators();

	return newData;
}