#pragma once


typedef struct simulationData {

	char* date;
	float money;
	int stock;

}SIMULATION_DATA, * P_SIMULATION_DATA;

P_SIMULATION_DATA createSimulationData(char[], float, int);