
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tradingPlans.h"
#include "mainMenu.h"


P_TRADE_CONDITION initializeTradingPlan() {

	P_TRADE_CONDITION tradingPlan = (P_TRADE_CONDITION)malloc(4 * sizeof(TRADE_CONDITION));

	for (int i = 0; i < 4; i++) {
		tradingPlan[i].conditionStatus = EMPTY;
	}

	return tradingPlan;
}

void createTradingPlan(P_TRADE_CONDITION tradingPlan) {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("~~~~~~~~~~~~~~~ CREATE TRADING PLAN ~~~~~~~~~~~~~~~~~\n", stdout);
	fputs("What would you like to do?\n", stdout);
	fputs("a) Add a trade condition\n", stdout);
	fputs("b) View all trade conditions\n", stdout);
	fputs("c) Delete a trade condition\n", stdout);
	fputs("d) Quit to main menu\n", stdout);

	while (true) {

		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0;

		if (!strcmp("a", userInput)) {
			addTradeCondition(tradingPlan);
		}
		else if (!strcmp("b", userInput)) {

		}
		else if (!strcmp("c", userInput)) {

		}
		else if (!strcmp("d", userInput)) {

		}
	}

}

void addTradeCondition(P_TRADE_CONDITION tradingPlan) {

	int emptyConditionIndex = 0;
	int i = 0;

	for (i = 0; i < 4; i++) {
		if (tradingPlan[i].conditionStatus == EMPTY)
			break;
		else if (i == 4)
			printf("No empty conditions left.\n");
	}

	fputs("Sel")

	
}

