
#include "simulationDataNode.h"
#include "simulationData.h"
#include <stdlib.h>
#include <stdio.h>


P_SIMULATION_NODE createSimulationNode(P_SIMULATION_DATA data) {

	P_SIMULATION_NODE newNode = (P_SIMULATION_NODE)malloc(sizeof(SIMULATION_NODE));
	if (!newNode) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	newNode->nodeData = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void setSimulationNodeNextSimulationNode(P_SIMULATION_NODE sourceNode, P_SIMULATION_NODE newNextNode) {
	sourceNode->next = newNextNode;
}

void setSimulationNodePrevSimulationNode(P_SIMULATION_NODE newNode, P_SIMULATION_NODE prevNode) {
	newNode->prev = prevNode;
}