#pragma once
#include <stdbool.h>
#include "tradeConditionNode.h"
#include "tradeCondition.h"

typedef struct tradingConditionList {
	P_TRADE_CONDITION_NODE listHead;
	P_TRADE_CONDITION_NODE listTail;
}TRADE_CONDITION_LIST, *P_TRADE_CONDITION_LIST;

// PROTOTYPES
P_TRADE_CONDITION_LIST initializeTradeConditionList();
void printTradeConditionListMenu();
bool executeTradeConditionListUserOption(P_TRADE_CONDITION_LIST);
P_TRADE_CONDITION_NODE getTradeConditionListHeadNode(P_TRADE_CONDITION_LIST);
void addConditionToList(P_TRADE_CONDITION_LIST, P_TRADE_CONDITION);
void printTradeConditionList(P_TRADE_CONDITION_LIST);
