
#include "tradeConditionList.h"
#include "tradeConditionNode.h"
#include "mainMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

P_TRADE_CONDITION_LIST createTradeConditionList() {

	P_TRADE_CONDITION_LIST list = (P_TRADE_CONDITION_LIST)malloc(sizeof(TRADE_CONDITION_LIST));
	if (!list) {
		fprintf(stderr, "Error allocating memory.\n");
		exit(EXIT_FAILURE);
	}

	list->listHead = NULL;
	list->listTail = NULL;

	return list;
}

void tradeConditionListMenu(P_TRADE_CONDITION_LIST list) {

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

P_TRADE_CONDITION_LIST getHeadNode(P_TRADE_CONDITION_LIST list) {
	return list->listHead;
}

void addPlanToList(P_TRADE_CONDITION_LIST list, P_TRADE_CONDITION newPlan) {

	P_TRADE_CONDITION_NODE newNode = createPlanNode(newPlan);

	if (getHeadListNode(list) == NULL) {
		list->listHead = newNode;
		list->listTail = newNode;
	}
	else {
		setPlanNodeNextPlanNode(list->listTail, newNode);
		setPlanNodePrevPlanNode(newNode, list->listTail);
		list->listTail = newNode;
	}
}