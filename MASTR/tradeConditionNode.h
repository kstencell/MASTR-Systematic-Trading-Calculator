#pragma once

#include "tradeCondition.h"


typedef struct tradeConditionNode {

	P_TRADE_CONDITION nodeData;
	struct tradingPlanNode* next;
	struct tradingPlanNode* prev;

}TRADE_CONDITION_NODE, *P_TRADE_CONDITION_NODE;

P_TRADE_CONDITION_NODE createPlanNode(P_TRADE_CONDITION);
void setPlanNodeNextPlanNode(P_TRADE_CONDITION_NODE, P_TRADE_CONDITION_NODE);
void setPlanNodePrevPlanNode(P_TRADE_CONDITION_NODE, P_TRADE_CONDITION_NODE);