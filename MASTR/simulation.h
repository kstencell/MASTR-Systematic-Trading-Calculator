#pragma once

#include "simulationData.h"
#include "simulationDataNode.h"
#include "tradeCondition.h"
#include "tradeConditionNode.h"
#include "tradeConditionList.h"
#include "data.h"
#include "dataNode.h"
#include "historicalData.h"\

typedef struct simulationList {
	P_SIMULATION_NODE listHead;
	P_SIMULATION_NODE listTail;
}SIMULATION_LIST, *P_SIMULATION_LIST;

P_SIMULATION_LIST createSimulationList();
P_SIMULATION_NODE getSimulationHeadNode(P_SIMULATION_LIST);
void addDataToSimulationList(P_SIMULATION_LIST, P_SIMULATION_DATA);

void runSimulation(P_DATA_LIST, P_TRADE_CONDITION_LIST);
void checkTradeConditionList(P_SIMULATION_DATA, P_TRADE_CONDITION_LIST, P_DATA_NODE);
bool isTradeConditionTriggered(P_TRADE_CONDITION_NODE, P_DATA_NODE);
bool executeTrade(P_SIMULATION_DATA, P_TRADE_CONDITION_NODE, P_DATA_NODE);
void printSimulationResults(P_SIMULATION_LIST, P_DATA_LIST);


