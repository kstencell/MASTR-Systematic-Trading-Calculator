#pragma once

#include "simulationData.h"
#include "simulationDataNode.h"

typedef struct simulationList {
	P_SIMULATION_NODE listHead;
	P_SIMULATION_NODE listTail;
}SIMULATION_LIST, *P_SIMULATION_LIST;

P_SIMULATION_LIST createSimulationList();
P_SIMULATION_NODE getSimulationHeadNode(P_SIMULATION_LIST);
void addDataToSimulationList(P_SIMULATION_LIST, P_SIMULATION_DATA);
