#pragma once

#include <stdbool.h>
#include "data.h"
#include "dataNode.h"

#define LINE_MAX		100

typedef struct dataList {
	P_DATA_NODE listHead;
	P_DATA_NODE listTail;
}DATA_LIST, * P_DATA_LIST;

// PROTOTYPES
P_DATA_LIST createList();
P_DATA_NODE getHeadNode(P_DATA_LIST);
void addDataToList(P_DATA_LIST, P_DATA);
bool loadDataFromDisk(P_DATA_LIST, char[]);