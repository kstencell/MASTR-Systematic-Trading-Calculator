#pragma once

#include "tradeCondition.h"


typedef struct tradeConditionNode {

	P_TRADE_CONDITION nodeData;
	struct tradeConditionNode* next;
	struct tradeConditionNode* prev;

}TRADE_CONDITION_NODE, *P_TRADE_CONDITION_NODE;

P_TRADE_CONDITION_NODE createTradeConditionNode(P_TRADE_CONDITION);
void setTradeConditionNodeNextTradeConditionNode(P_TRADE_CONDITION_NODE, P_TRADE_CONDITION_NODE);
void setTradeConditionNodePrevTradeConditionNode(P_TRADE_CONDITION_NODE, P_TRADE_CONDITION_NODE);
void printTradeConditionNode(P_TRADE_CONDITION_NODE);