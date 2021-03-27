
//#include "tradingPlanList.h"
//#include "tradingPlanNode.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//P_TRADING_PLAN_LIST createPlanList() {
//
//	P_TRADING_PLAN_LIST list = (P_TRADING_PLAN_LIST)malloc(sizeof(TRADING_PLAN));
//	if (!list) {
//		fprintf(stderr, "Error allocating memory.\n");
//		exit(EXIT_FAILURE);
//	}
//
//	list->listHead = NULL;
//	list->listTail = NULL;
//
//	return list;
//}
//
//P_TRADING_PLAN_NODE getHeadPlanNode(P_TRADING_PLAN_LIST list) {
//	return list->listHead;
//}
//
//void addPlanToList(P_TRADING_PLAN_LIST list, P_TRADING_PLAN newPlan) {
//
//	P_TRADING_PLAN_NODE newNode = createPlanNode(newPlan);
//
//	if (getHeadPlanNode(list) == NULL) {
//		list->listHead = newNode;
//		list->listTail = newNode;
//	}
//	else {
//		setPlanNodeNextPlanNode(list->listTail, newNode);
//		setPlanNodePrevPlanNode(newNode, list->listTail);
//		list->listTail = newNode;
//	}
//}