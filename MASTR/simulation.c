
#include "simulation.h"
#include "simulationDataNode.h"
#include "simulationData.h"
#include "tradeConditionList.h"
#include "historicalData.h"
#include <stdlib.h>
#include <stdio.h>

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
		list->listHead = NULL;
		list->listTail = NULL;
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
	}
}

bool executeTrade(P_SIMULATION_DATA newSimulationData, P_TRADE_CONDITION_NODE tradeCondition, P_DATA_NODE dataNode) {

}