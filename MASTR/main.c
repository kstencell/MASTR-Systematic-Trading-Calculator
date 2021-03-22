#include <stdio.h>
#include <stdlib.h>
#include "historicalData.h"
#include "dataNode.h"
#include "data.h"

int main(int argc, char* argv[]) {

	P_DATA_LIST historicalData = createList();

	if (!loadDataFromDisk(historicalData, argv[1])) {
		fprintf(stderr, "No historical data found.");
		exit(EXIT_FAILURE);
	}

	printf("%s", historicalData->listTail->nodeData->date);

	return 0;
}