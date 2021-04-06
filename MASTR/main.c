#include <stdio.h>
#include <stdlib.h>
#include "historicalData.h"
#include "dataNode.h"
#include "data.h"
#include "indicators.h"
#include "tradeConditionList.h"
#include "tradeCondition.h"
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

	P_TRADE_CONDITION_LIST tradeConditionList = initializeTradeConditionList();

	//printf("%s", historicalData->listTail->nodeData->date);

	bool continueMainMenu = true;
	do {
		bool continueMainMenu = true;
		printMainMenuOptions();
		continueMainMenu = executeMainMenuOptionChoice(historicalData, tradeConditionList);
	} while (continueMainMenu);

	return 0;
}