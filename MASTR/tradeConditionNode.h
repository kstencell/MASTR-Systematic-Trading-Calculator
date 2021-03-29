#pragma once

#include "tradeCondition.h"


typedef struct tradeConditionNode {

	P_TRADE_CONDITION nodeData;
	struct tradeConditionNode* next;
	struct tradeConditionNode* prev;

}TRADE_CONDITION_NODE, *P_TRADE_CONDITION_NODE;

P_TRADE_CONDITION_NODE createNode(P_TRADE_CONDITION);
void setListNodeNextListNode(P_TRADE_CONDITION_NODE, P_TRADE_CONDITION_NODE);
void setListNodePrevListNode(P_TRADE_CONDITION_NODE, P_TRADE_CONDITION_NODE);