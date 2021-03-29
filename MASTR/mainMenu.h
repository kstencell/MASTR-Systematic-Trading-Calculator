#pragma once

#include "tradeConditions.h"
#include "historicalData.h"

#define MAX_USER_INPUT_LEN		20

void printMainMenuOptions();
void executeMainMenuOptionChoice(P_DATA_LIST, P_TRADE_CONDITION);
void mainMenu();

