#pragma once

#include "data.h"

typedef struct dataNode {
	P_DATA nodeData;
	struct dataNode* next;
	struct dataNode* prev;
}DATA_NODE, *P_DATA_NODE;

//PROTOTYPES
P_DATA_NODE createNode(P_DATA);
void setNodeNextNode(P_DATA_NODE, P_DATA_NODE);
void setNodePrevNode(P_DATA_NODE, P_DATA_NODE);
