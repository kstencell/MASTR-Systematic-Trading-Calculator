#include <stdio.h>
#include <stdlib.h>
#include "historicalData.h"
#include "dataNode.h"
#include "data.h"
#include "indicators.h"
#include "tradingPlans.h"
#include "mainMenu.h"

int main(int argc, char* argv[]) {

	P_DATA_LIST historicalData = createList();

	if (!loadDataFromDisk(historicalData, argv[1])) {
		fprintf(stderr, "No historical data found.");
		exit(EXIT_FAILURE);
	}

	/*printf("%s", historicalData->listTail->nodeData->date);
	printf("%s", historicalData->listTail->nodeData->date);*/

	computeIndicators(historicalData);

	P_TRADE_CONDITION tradingPlan = initializeTradingPlan();

	printf("%s", historicalData->listTail->nodeData->date);

	while (true) {
		printMainMenuOptions();
		executeMainMenuOptionChoice(historicalData, tradingPlan);
	}

	return 0;
}