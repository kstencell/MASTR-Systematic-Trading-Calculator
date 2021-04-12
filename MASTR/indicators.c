
#include <stdio.h>
#include <stdlib.h>
#include "indicators.h"
#include "historicalData.h"
#include "dataNode.h"
#include "data.h"

P_INDICATORS createIndicators() {

	P_INDICATORS newIndicators = (P_INDICATORS)malloc(sizeof(INDICATORS));
	if (!newIndicators) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	return newIndicators;
}

void computeIndicators(P_DATA_LIST list) {

	P_DATA_NODE current = list->listHead;

	for (int i = 0; current != NULL; i++) {
		current->nodeData->indicators->SMA10 = 0;
		current->nodeData->indicators->SMA25 = 0;
		current->nodeData->indicators->SMA50 = 0;
		current->nodeData->indicators->EMA5 = 0;
		if (i > 4)
			current->nodeData->indicators->EMA5 = computeEMA(current);
		if (i > 8)
			current->nodeData->indicators->SMA10 = computeSMA(current, 10);
		if (i > 23)
			current->nodeData->indicators->SMA25 = computeSMA(current, 25);
		if (i > 48)
			current->nodeData->indicators->SMA50 = computeSMA(current, 50);

		current = current->next;
	}
}

float computeSMA(P_DATA_NODE current, int duration) {

	P_DATA_NODE traversingNode = current;
	float runningTotal = 0;

	for (int i = 0; i < duration; i++) {
		runningTotal += traversingNode->nodeData->close;
		traversingNode = traversingNode->prev;
	}

	float SMA = runningTotal / duration;

	return SMA;
}

float computeEMA(P_DATA_NODE current) {
	float closingPriceOne = 0.0, emaPrev = 0.0, smoothFactor = 2.0, numDays = 6.0;  // numDays -- portion of ema equation is smooth / 1 + desired days (5)
	float EMA = 0.0;

		if (current->prev->nodeData->indicators->EMA5 == 0) {

			closingPriceOne = current->nodeData->close;
			emaPrev = computeSMA(current, 5);

	    }
		else {
			closingPriceOne = current->nodeData->close;
			getPrevNode(current);
			emaPrev = current->nodeData->indicators->EMA5;
		}

	EMA = closingPriceOne * (smoothFactor / numDays) +  emaPrev * (1 - (smoothFactor / numDays));
	return EMA;

}

void getPrevNode(P_DATA_NODE current) {
	current = current->prev;
	return current;
}