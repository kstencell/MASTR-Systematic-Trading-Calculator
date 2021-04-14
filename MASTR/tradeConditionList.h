#pragma once
#include <stdbool.h>
#include <stdio.h>
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
int getLengthOfConditionList(P_TRADE_CONDITION_LIST);
void addConditionToList(P_TRADE_CONDITION_LIST, P_TRADE_CONDITION);
void deleteConditionOption(P_TRADE_CONDITION_LIST);
void removeConditionFromList(P_TRADE_CONDITION_LIST, int);
void printTradeConditionList(P_TRADE_CONDITION_LIST);
bool saveTradeConditionListToDisk(P_TRADE_CONDITION_LIST, char[]);
void streamPrintTradeConditionList(FILE*, P_TRADE_CONDITION_LIST);
bool loadTradeConditionListFromFile(P_TRADE_CONDITION_LIST, char[]);
//void checkTradeConditionList(P_SIMULATION_DATA, P_TRADE_CONDITION_LIST, P_DATA_NODE);



