
#include "simulation.h"
#include "simulationDataNode.h"
#include "simulationData.h"
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