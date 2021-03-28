#include "historicalData.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

P_DATA_LIST createList() {

	P_DATA_LIST list = (P_DATA_LIST)malloc(sizeof(DATA_LIST));
	if (!list) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	list->listHead = NULL;
	list->listTail = NULL;

	return list;
}

P_DATA_NODE getHeadNode(P_DATA_LIST list) {
	return list->listHead;
}

void addDataToList(P_DATA_LIST list, P_DATA newData) {

	P_DATA_NODE newNode = createNode(newData);

	if (getHeadNode(list) == NULL) {
		list->listHead = newNode;
		list->listTail = newNode;
	}
	else {
		setNodeNextNode(list->listTail, newNode);
		setNodePrevNode(newNode, list->listTail);
		list->listTail = newNode;
	}
}

bool loadDataFromDisk(P_DATA_LIST list, char filename[]) {

	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)
		return false;

	char line[LINE_MAX];
	char dailyVals[7][15];
	float open, high, low, close;
	char* pEnd;
	unsigned long volume;

	while (fgets(line, LINE_MAX, fp) != NULL) {
		if (line[0] == 'D')
			continue;

		char* ptr;
		ptr = strtok(line, ",");
		for (int i = 0; ptr != NULL; i++) {
			strcpy(dailyVals[i], ptr);
			ptr = strtok(NULL, ",");
		}

		open = strtod(dailyVals[1], NULL);
		high = strtod(dailyVals[2], NULL);
		low = strtod(dailyVals[3], NULL);
		close = strtod(dailyVals[4], NULL);
		volume = strtoul(dailyVals[6], NULL, 10);

		P_DATA newData = createData(dailyVals[0], open, high, low, close, volume);
		addDataToList(list, newData);
	}

	return true;
}