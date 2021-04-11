
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
			printTradeConditionList(tradeConditionList);
			return true;
		}
		else if (!strcmp("c", userInput)) {
			deleteConditionOption(tradeConditionList);
			return true;
		}
		else if (!strcmp("d", userInput)) {
			return false;
		}
	}
}

P_TRADE_CONDITION_NODE getTradeConditionListHeadNode(P_TRADE_CONDITION_LIST tradeConditionlist) {
	return tradeConditionlist->listHead;
}

int getLengthOfConditionList(P_TRADE_CONDITION_LIST tradeConditionList) {

	int numberOfConditions = 0;

	if (getTradeConditionListHeadNode(tradeConditionList) == NULL) {
		return numberOfConditions;
	}
	else {
		P_TRADE_CONDITION_NODE current = tradeConditionList->listHead;
		while (current != NULL) {
			numberOfConditions++;
			current = current->next;
		}
	}

	return;
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

void deleteConditionOption(P_TRADE_CONDITION_LIST tradeConditionList) {

	if (getTradeConditionListHeadNode(tradeConditionList) == NULL) {
		printf("There are no conditions to delete.\n");
		return;
	}

	printTradeConditionList(tradeConditionList);
	printf("\nWhich condition would you like to delete (enter condition number)(0 to quit): ");

	int conditionNumberMax = getLengthOfConditionList(tradeConditionList);
	int conditionNumberToDelete;
	bool validChoice = false;

	while (!validChoice) {
		conditionNumberToDelete = getNumberFromUser();

		if (conditionNumberToDelete < 1 || conditionNumberToDelete > conditionNumberMax) {
			printf("Not a valid option. Try again.\n");
			validChoice = false;
		}
		else if (conditionNumberToDelete == 0) {
			validChoice = true;
			return;
		}
		else {
			removeConditionFromList(tradeConditionList, conditionNumberToDelete);
			printf("Condition number %d has been deleted\n", conditionNumberToDelete);
			validChoice = true;
		}
	}
}

void removeConditionFromList(P_TRADE_CONDITION_LIST tradeConditionList, int conditionNumberToDelete) {

	P_TRADE_CONDITION_NODE current = tradeConditionList->listHead;
	//P_TRADE_CONDITION_NODE prev = NULL;

	int i = 1;
	while (i != conditionNumberToDelete) {
		//prev = current;
		current = current->next;
		i++;
	}
	if (current->prev == NULL && current->next == NULL) {
		tradeConditionList->listHead = NULL;
		tradeConditionList->listTail = NULL;
	}
	else if (current->prev == NULL) {
		setTradeConditionNodePrevTradeConditionNode(current->next, NULL);
		tradeConditionList->listHead = current->next;
	}
	else if (current->next == NULL) {
		setTradeConditionNodeNextTradeConditionNode(current->prev, NULL);
		tradeConditionList->listTail = current->prev;
	}
	else {
		setTradeConditionNodeNextTradeConditionNode(current->prev, current->next);
		setTradeConditionNodePrevTradeConditionNode(current->next, current->prev);
	}

	deleteTradeConditionNode(current);

}

void printTradeConditionList(P_TRADE_CONDITION_LIST tradeConditionList) {

	if (getTradeConditionListHeadNode(tradeConditionList) == NULL) {
		printf("There are no trade conditions.\n");
		return;
	}
	else {

		P_TRADE_CONDITION_NODE current = tradeConditionList->listHead;

		int conditionNumber = 1;
		while (current != NULL) {
			printf("Condition Number: %d\n", conditionNumber);
			printTradeConditionNode(current);
			current = current->next;
			conditionNumber++;
			printf("\n");
		}
	}

	return;
}

bool saveTradeConditionListToDisk(P_TRADE_CONDITION_LIST tradeConditionList, char filename[]) {

	FILE* fp;
	if ((fp = fopen(filename, "w+")) == NULL)
		return false;

	streamPrintTradeConditionList(fp, tradeConditionList);

	fclose(fp);

	return true;
}

void streamPrintTradeConditionList(FILE* fp, P_TRADE_CONDITION_LIST tradeConditionList) {

	if (tradeConditionList->listHead == NULL) {
		fprintf(stderr, "\nNo trade conditions to print.\n");
		return;
	}
	else {
		P_TRADE_CONDITION_NODE current = tradeConditionList->listHead;

		while (current != NULL) {
			streamPrintTradeCondition(fp, current->nodeData);
			current = current->next;
		}
	}
}

bool loadTradeConditionListFromFile(P_TRADE_CONDITION_LIST tradeConditionList, char filename[]) {

	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)
		return false;

	while (!feof(fp)) {
		P_TRADE_CONDITION condition = initializeTradeCondition();
		streamReadTradeConditionFromFile(fp, condition);
		addConditionToList(tradeConditionList, condition);
	}

	return true;
}

//void checkTradeConditionList(P_SIMULATION_DATA newSimulationData, P_TRADE_CONDITION_LIST tradeConditionList, P_DATA_NODE currentDataNode) {
//
//	P_TRADE_CONDITION_NODE currentTradeCondition = tradeConditionList->listHead;
//
//	while (currentTradeCondition != NULL) {
//		if (isTradeConditionTriggered(currentTradeCondition, currentDataNode)) {
//			if (executeTrade(newSimulationData, currentTradeCondition, currentDataNode)) {
//				printf("Trade executed on %s", newSimulationData->date);
//			}
//			return;
//		}
//		else {
//			currentTradeCondition = currentTradeCondition->next;
//		}
//	}
//
//	return;
//}

