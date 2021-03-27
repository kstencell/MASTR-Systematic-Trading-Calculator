#pragma once
#include "tradeConditionNode.h"
#include "tradeCondition.h"

typedef struct tradingConditionList {
	P_TRADE_CONDITION_NODE listHead;
	P_TRADE_CONDITION_NODE listTail;
}TRADING_CONDITION_LIST, *P_TRADE_CONDITION_LIST;

// PROTOTYPES
P_TRADE_CONDITION_LIST createTradingConditionList();
P_TRADE_CONDITION_NODE getHeadPlanNode(P_TRADE_CONDITION_LIST);
void addConditionToList(P_TRADE_CONDITION_LIST, P_TRADE_CONDITION);