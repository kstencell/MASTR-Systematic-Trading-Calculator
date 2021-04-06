#pragma once

#include <stdbool.h>
#include "tradeCondition.h"
#include "tradeConditionList.h"
#include "historicalData.h"

#define MAX_USER_INPUT_LEN		20

void printMainMenuOptions();
bool executeMainMenuOptionChoice(P_DATA_LIST, P_TRADE_CONDITION_LIST);

