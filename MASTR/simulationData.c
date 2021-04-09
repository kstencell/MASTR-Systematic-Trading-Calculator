
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simulationData.h"

P_SIMULATION_DATA createSimulationData(char date[], float money, int stock) {

	P_SIMULATION_DATA newSimulationData = (P_SIMULATION_DATA)malloc(sizeof(SIMULATION_DATA));
	if (!newSimulationData) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	newSimulationData->date = (char*)malloc(sizeof(char) * 10);
	strcpy(newSimulationData->date, date);
	newSimulationData->money = money;
	newSimulationData->stock = stock;

	return newSimulationData;
}