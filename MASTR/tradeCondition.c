
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "tradeCondition.h"
#include "mainMenu.h"


P_TRADE_CONDITION createTradeCondition() {

	P_TRADE_CONDITION tradeCondition = (P_TRADE_CONDITION)malloc(sizeof(TRADE_CONDITION));

	tradeCondition->conditionStatus = EMPTY;

	return tradeCondition;
}

void createTradeCondition(P_TRADE_CONDITION tradeConditionList) {

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
			addTradeCondition(tradeConditionList);
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

	P_TRADE_CONDITION newCondition = createTradeCondition();

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	selectConditionType(newCondition);
	selectIndicatorType(newCondition);
	selectThresholdType(newCondition);
}

void selectConditionType(P_TRADE_CONDITION condition) {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("Select a condition type\n", stdout);
	fputs("a) Buy\n", stdout);
	fputs("b) Sell\n", stdout);
	while (true) {
		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0;

		if (!strcmp("a", userInput)) {
			condition->conditionType = BUY;
			return;
		}
		else if (!strcmp("b", userInput)) {
			condition->conditionType = SELL;
			return;
		}
		else {
			fputs("Not a valid input, please try again.\n\n", stdout);
		}
	}
}

void selectIndicatorType(P_TRADE_CONDITION condition) {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("Select an indicator type\n", stdout);
	fputs("a) Simple Moving Average (10 days)\n", stdout);
	fputs("b) Simple Moving Average (25 days)\n", stdout);
	fputs("c) Simple Moving Average (50 days)\n", stdout);
	while (true) {
		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0;

		if (!strcmp("a", userInput)) {
			condition->indicatorType = SMA10;
			return;
		}
		else if (!strcmp("b", userInput)) {
			condition->indicatorType = SMA25;
			return;
		}
		else if (!strcmp("c", userInput)) {
			condition->indicatorType = SMA50;
			return;
		}
		else {
			fputs("Not a valid input, please try again.\n\n", stdout);
		}
	}
}

void selectThresholdType(P_TRADE_CONDITION condition) {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("Select a threshold type\n", stdout);
	fputs("a) Percentage\n", stdout);
	fputs("b) Absolute\n", stdout);
	while (true) {
		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0;

		if (!strcmp("a", userInput)) {
			condition->thresholdType = PERCENTAGE;
			return;
		}
		else if (!strcmp("b", userInput)) {
			condition->thresholdType = PERCENTAGE;
			return;
		}
		else {
			fputs("Not a valid input, please try again.\n\n", stdout);
		}
	}
}

void selectThresholdDirection(P_TRADE_CONDITION condition) {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("Select a threshold direction\n", stdout);
	fputs("a) Greater than\n", stdout);
	fputs("b) Greater than or equal to\n", stdout);
	fputs("c) Less than\n", stdout);
	fputs("d) Less than or equal to\n", stdout);
	while (true) {
		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0;

		if (!strcmp("a", userInput)) {
			condition->thresholdDirection = GREATER_THAN;
			return;
		}
		else if (!strcmp("b", userInput)) {
			condition->thresholdDirection = GREAT_THAN_OR_EQUAL;
			return;
		}
		else if (!strcmp("c", userInput)) {
			condition->thresholdDirection = LESS_THAN;
			return;
		}
		else if (!strcmp("d", userInput)) {
			condition->thresholdDirection = LESS_THAN_OR_EQUAL;
			return;
		}
		else {
			fputs("Not a valid input, please try again.\n\n", stdout);
		}
	}
}