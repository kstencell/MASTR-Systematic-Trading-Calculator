
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
