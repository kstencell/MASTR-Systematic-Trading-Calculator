#include <stdlib.h>
#include <stdio.h>
#include "dataNode.h"
#include "data.h"

P_DATA_NODE createNode(P_DATA data) {

	P_DATA_NODE newNode = (P_DATA_NODE)malloc(sizeof(DATA_NODE));
	if (!newNode) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	newNode->nodeData = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void setNodeNextNode(P_DATA_NODE sourceNode, P_DATA_NODE newNextNode) {
	sourceNode->next = newNextNode;
}

void setNodePrevNode(P_DATA_NODE newNode, P_DATA_NODE prevNode) {
	newNode->prev = prevNode;
}