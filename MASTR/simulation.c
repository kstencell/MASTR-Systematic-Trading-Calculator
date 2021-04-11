
#include "simulation.h"
#include "simulationDataNode.h"
#include "simulationData.h"
#include "tradeConditionList.h"
#include "historicalData.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

P_SIMULATION_LIST createSimulationList() {

	P_SIMULATION_LIST list = (P_SIMULATION_LIST)malloc(sizeof(SIMULATION_LIST));
	if (!list) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	list->listHead = NULL;
	list->listTail = NULL;

	return list;
}

P_SIMULATION_NODE getSimulationHeadNode(P_SIMULATION_LIST list) {
	return list->listHead;
}

void addDataToSimulationList(P_SIMULATION_LIST list, P_SIMULATION_DATA newData) {

	P_SIMULATION_NODE newNode = createSimulationNode(newData);

	if (getSimulationHeadNode(list) == NULL) {
		list->listHead = newNode;
		list->listTail = newNode;
	}
	else {
		setSimulationNodeNextSimulationNode(list->listTail, newNode);
		setSimulationNodePrevSimulationNode(newNode, list->listTail);
		list->listTail = newNode;
	}

}

void runSimulation(P_DATA_LIST historicalDataList, P_TRADE_CONDITION_LIST tradeConditionList) {

	P_SIMULATION_LIST simulationList = createSimulationList();
	P_DATA_NODE currentDataNode = getHeadNode(historicalDataList);

	printf("How much money would you like to start with: ");
	double startingAmount = (float)getNumberFromUser();

	P_SIMULATION_DATA newSimulationData = createSimulationData(currentDataNode->nodeData->date, startingAmount, 0);
	addDataToSimulationList(simulationList, newSimulationData);
	currentDataNode = currentDataNode->next;

	while (currentDataNode != NULL) {
		newSimulationData = createSimulationData(currentDataNode->nodeData->date, simulationList->listTail->nodeData->money, simulationList->listTail->nodeData->stock);
		checkTradeConditionList(newSimulationData, tradeConditionList, currentDataNode);
		addDataToSimulationList(simulationList, newSimulationData);
		currentDataNode = currentDataNode->next;
	}

	printSimulationResults(simulationList, historicalDataList);

	return;
}

void checkTradeConditionList(P_SIMULATION_DATA newSimulationData, P_TRADE_CONDITION_LIST tradeConditionList, P_DATA_NODE currentDataNode) {

	P_TRADE_CONDITION_NODE currentTradeCondition = tradeConditionList->listHead;

	while (currentTradeCondition != NULL) {
		if (isTradeConditionTriggered(currentTradeCondition, currentDataNode)) {
			if (executeTrade(newSimulationData, currentTradeCondition, currentDataNode)) {
				printf("Trade executed on %s\n\n", newSimulationData->date);
			}
			return;
		}
		else {
			currentTradeCondition = currentTradeCondition->next;
		}
	}

	return;
}

bool isTradeConditionTriggered(P_TRADE_CONDITION_NODE tradeCondition, P_DATA_NODE dataNode) {

	float absoluteDifference = 0;
	float percentDifference = 0;

	switch (tradeCondition->nodeData->indicatorType)
	{
	case SMA10:
		if (dataNode->prev->nodeData->indicators->SMA10 == 0)
			return false;
		else {

			absoluteDifference = dataNode->nodeData->indicators->SMA10 - dataNode->prev->nodeData->indicators->SMA10;
			percentDifference = (absoluteDifference / dataNode->nodeData->indicators->SMA10) * 100;
			break;
		}
	case SMA25:
		if (dataNode->prev->nodeData->indicators->SMA25 == 0)
			return false;
		else {

			absoluteDifference = dataNode->nodeData->indicators->SMA25 - dataNode->prev->nodeData->indicators->SMA25;
			percentDifference = (absoluteDifference / dataNode->nodeData->indicators->SMA25) * 100;
			break;
		}
	case SMA50:
		if (dataNode->prev->nodeData->indicators->SMA50 == 0)
			return false;
		else {

			absoluteDifference = dataNode->nodeData->indicators->SMA50 - dataNode->prev->nodeData->indicators->SMA50;
			percentDifference = (absoluteDifference / dataNode->nodeData->indicators->SMA50) * 100;
			break;
		}
	}

	switch (tradeCondition->nodeData->thresholdDirection) {
	case GREATER_THAN:
		if (percentDifference > tradeCondition->nodeData->thresholdValue)
			return true;
		break;
	case GREATER_THAN_OR_EQUAL:
		if (percentDifference >= tradeCondition->nodeData->thresholdValue)
			return true;
		break;
	case LESS_THAN:
		if (percentDifference < tradeCondition->nodeData->thresholdValue)
			return true;
		break;
	case LESS_THAN_OR_EQUAL:
		if (percentDifference < tradeCondition->nodeData->thresholdValue)
			return true;
		break;
	}

	return false;
}

bool executeTrade(P_SIMULATION_DATA newSimulationData, P_TRADE_CONDITION_NODE tradeCondition, P_DATA_NODE dataNode) {

	float amountOfStock;
	float currentMoney = newSimulationData->money;
	float stockClose = dataNode->nodeData->close;

	switch (tradeCondition->nodeData->conditionType) {
		case BUY:
			amountOfStock = floorf(currentMoney / stockClose);
			if (amountOfStock >= 1) {
				newSimulationData->money = currentMoney - (amountOfStock * stockClose);
				newSimulationData->stock += amountOfStock;
				printf("BOUGHT\n");
				return true;
			}
			else
				return false;
		case SELL:
			if (newSimulationData->stock > 0) {
				newSimulationData->money += (newSimulationData->stock * stockClose);
				newSimulationData->stock = 0;
				printf("SOLD\n");
				return true;
			}
			return false;
	}
}

void printSimulationResults(P_SIMULATION_LIST simulationList, P_DATA_LIST historicalDataList) {

	printf("******* SIMULATION RESULTS ********\n");
	float startingCapital = simulationList->listHead->nodeData->money;
	printf("Starting capital = %.2f\n", startingCapital);
	float endingCapital = simulationList->listTail->nodeData->money + (historicalDataList->listTail->nodeData->close * simulationList->listTail->nodeData->stock);
	printf("Ending capital = %.2f\n", endingCapital);
	float roi = ((endingCapital - startingCapital) / startingCapital) * 100;
	printf("ROI = %.2f percent\n", roi);
	printf("***********************************\n");
	printf("\n\n");

	printf("****** RESULTS IF JUST HELD *******\n");
	printf("Starting capital = %.2f\n", startingCapital);
	int amountOfStock = floorf(startingCapital / historicalDataList->listHead->nodeData->close);
	int initialStock = 0;
	int initialCash = startingCapital;
	if (amountOfStock >= 1) { 
		initialStock += amountOfStock;
		initialCash -= amountOfStock * historicalDataList->listHead->nodeData->close;
	}
	endingCapital = initialCash + (amountOfStock * historicalDataList->listTail->nodeData->close);
	printf("Ending capital = %.2f\n", endingCapital);
	roi = ((endingCapital - startingCapital) / startingCapital) * 100;
	printf("ROI = %.2f percent\n", roi);
	printf("***********************************\n");
	printf("\n\n");

	return;
}