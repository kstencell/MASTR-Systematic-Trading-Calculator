#pragma once
#include "tradingPlanNode.h"
#include "tradingPlans.h"

typedef struct tradingPlanList {
	P_TRADING_PLAN_NODE listHead;
	P_TRADING_PLAN_NODE listTail;
}TRADING_PLAN_LIST, * P_TRADING_PLAN_LIST;

// PROTOTYPES
P_TRADING_PLAN_LIST createPlanList();
P_TRADING_PLAN_NODE getHeadPlanNode(P_TRADING_PLAN_LIST);
void addPlanToList(P_TRADING_PLAN_LIST, P_TRADING_PLAN);