
#pragma once

#include "simulationData.h"

typedef struct simulationDataNode {
	P_SIMULATION_DATA nodeData;
	struct simulationDataNode* next;
	struct simulationDataNode* prev;
}SIMULATION_NODE, *P_SIMULATION_NODE;

P_SIMULATION_NODE createSimulationNode(P_SIMULATION_DATA);
void setSimulationNodeNextSimulationNode(P_SIMULATION_NODE, P_SIMULATION_NODE);
void setSimulationNodePrevSimulationNode(P_SIMULATION_NODE, P_SIMULATION_NODE);