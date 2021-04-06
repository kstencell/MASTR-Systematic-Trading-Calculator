
#include <stdlib.h>
#include <stdio.h>
#include "tradeConditionNode.h"

P_TRADE_CONDITION_NODE createTradeConditionNode(P_TRADE_CONDITION plan) {

	P_TRADE_CONDITION_NODE newNode = (P_TRADE_CONDITION_NODE)malloc(sizeof(TRADE_CONDITION_NODE));
	if (!newNode) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	newNode->nodeData = plan;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void setTradeConditionNodeNextTradeConditionNode(P_TRADE_CONDITION_NODE sourceNode, P_TRADE_CONDITION_NODE newNextNode) {
	sourceNode->next = newNextNode;
}

void setTradeConditionNodePrevTradeConditionNode(P_TRADE_CONDITION_NODE newNode, P_TRADE_CONDITION_NODE prevNode) {
	newNode->prev = prevNode;
}