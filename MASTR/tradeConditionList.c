
#include "tradeConditionList.h"
#include "tradeConditionNode.h"
#include "mainMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

P_TRADE_CONDITION_LIST initializeTradeConditionList() {

	P_TRADE_CONDITION_LIST list = (P_TRADE_CONDITION_LIST)malloc(sizeof(TRADE_CONDITION_LIST));
	if (!list) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	list->listHead = NULL;
	list->listTail = NULL;

	return list;
}

void printTradeConditionListMenu() {

	fputs("~~~~~~~~~~~~~~~ CREATE TRADING PLAN ~~~~~~~~~~~~~~~~~\n", stdout);
	fputs("What would you like to do?\n", stdout);
	fputs("a) Add a trade condition\n", stdout);
	fputs("b) View all trade conditions\n", stdout);
	fputs("c) Delete a trade condition\n", stdout);
	fputs("d) Quit to main menu\n", stdout);
	fputs("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n", stdout);
}

bool executeTradeConditionListUserOption(P_TRADE_CONDITION_LIST tradeConditionList) {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	while (true) {

		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0;

		if (!strcmp("a", userInput)) {
			P_TRADE_CONDITION newCondition = createTradeCondition();
			addConditionToList(tradeConditionList, newCondition);
			return true;
		}
		else if (!strcmp("b", userInput)) {

		}
		else if (!strcmp("c", userInput)) {

		}
		else if (!strcmp("d", userInput)) {
			return false;
		}
	}
}

P_TRADE_CONDITION_NODE getTradeConditionListHeadNode(P_TRADE_CONDITION_LIST tradeConditionlist) {
	return tradeConditionlist->listHead;
}

void addConditionToList(P_TRADE_CONDITION_LIST tradeConditionList, P_TRADE_CONDITION newCondition) {

	P_TRADE_CONDITION_NODE newNode = createTradeConditionNode(newCondition);

	if (getTradeConditionListHeadNode(tradeConditionList) == NULL) {
		tradeConditionList->listHead = newNode;
		tradeConditionList->listTail = newNode;
	}
	else {
		setTradeConditionNodeNextTradeConditionNode(tradeConditionList->listTail, newNode);
		setTradeConditionNodePrevTradeConditionNode(newNode, tradeConditionList->listTail);
		tradeConditionList->listTail = newNode;
	}
}