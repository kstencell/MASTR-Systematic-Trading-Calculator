
//#include <stdlib.h>
//#include <stdio.h>
//#include "tradingPlanNode.h"
//
//P_TRADING_PLAN_NODE createNode(P_TRADING_PLAN plan) {
//
//	P_TRADING_PLAN_NODE newNode = (P_TRADING_PLAN)malloc(sizeof(TRADING_PLAN));
//	if (!newNode) {
//		fprintf(stderr, "Error allocating memory.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	newNode->nodeData = plan;
//	newNode->next = NULL;
//	newNode->prev = NULL;
//
//	return newNode;
//}
//
//void setPlanNodeNextPlanNode(P_TRADING_PLAN_NODE sourceNode, P_TRADING_PLAN_NODE newNextNode) {
//	sourceNode->next = newNextNode;
//}
//
//void setPlanNodePrevPlanNode(P_TRADING_PLAN_NODE newNode, P_TRADING_PLAN_NODE prevNode) {
//	newNode->prev = prevNode;
//}