
#include "plot.h"
#include "pbPlots.h"
#include "supportLib.h"
#include "simulation.h"
#include "historicalData.h"

void plotSimulationData(P_DATA_LIST historicalData, P_SIMULATION_LIST simulationList) {

	RGBABitmapImageReference* imageRef = CreateRGBABitmapImageReference();

	float y_dailyNetWorth[daysInSimulation];
	char* x_dates[daysInSimulation];

	P_DATA_NODE currentHistoricalDataNode = getHeadNode(historicalData);
	P_SIMULATION_NODE currentSimulationDataNode = getSimulationHeadNode(simulationList);

	int counter = 0;
	while (currentSimulationDataNode != NULL) {
		y_dailyNetWorth[counter] = currentSimulationDataNode->nodeData->money + (currentHistoricalDataNode->nodeData->close * currentSimulationDataNode->nodeData->stock);
		//x_dates[counter] = currentSimulationDataNode->nodeData->date;
		x_dates[counter] = counter;

		currentHistoricalDataNode = currentHistoricalDataNode->next;
		currentSimulationDataNode = currentSimulationDataNode->next;

		counter++;
	}

	DrawScatterPlot(imageRef, 600, 400, x_dates, daysInSimulation, y_dailyNetWorth, daysInSimulation);

	size_t length;
	double* pngData = ConvertToPNG(&length, imageRef->image);
	WriteToFile(pngData, length, "plot.png");

	return;
}