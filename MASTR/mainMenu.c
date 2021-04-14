
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mainMenu.h"
#include "tradeConditionList.h"
#include "historicalData.h"
#include "simulation.h"

void printMainMenuOptions() {

	fputs("~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~\n", stdout);
	fputs("What would you like to do?\n", stdout);
	fputs("a) Customize your systematic trading plan\n", stdout);
	fputs("b) Load an existing trading plan from file\n", stdout);
	fputs("c) Save your current trading plan\n", stdout);
	fputs("d) Simulate your trading plan.\n", stdout);
	fputs("e) Quit\n", stdout);
	fputs("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n", stdout);
	fputs("Option: ", stdout);

}

bool executeMainMenuOptionChoice(P_DATA_LIST historicalData, P_TRADE_CONDITION_LIST tradeConditionList) {

	char userInput[MAX_USER_INPUT_LEN];

	while (true) {
		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0; // removes the newline char from user input

		if (!strcmp("a", userInput)) {
			bool continueTradeConditionMenu = true;
			do {
				printTradeConditionListMenu();
				continueTradeConditionMenu = executeTradeConditionListUserOption(tradeConditionList);
			} while (continueTradeConditionMenu);
			return true;
		}
		else if (!strcmp("b", userInput)) {
			if (!loadTradeConditionListFromFile(tradeConditionList, "tradeConditionList.txt"))
				fprintf(stderr, "\nError cannot load trade condition list from file.\n");
			else
				printf("Trade condition list load successful.\n");
			return true;
		}
		else if (!strcmp("c", userInput)) {
			if (!saveTradeConditionListToDisk(tradeConditionList, "tradeConditionList.txt"))
				fprintf(stderr, "\nError saving trade condition list to file.\n");
			else
				printf("Save successful.\n");
			return true;
		}
		else if (!strcmp("d", userInput)) {
			runSimulation(historicalData, tradeConditionList);
			return true;
		}
		else if (!strcmp("e", userInput)) {
			return false;
		}
		else {
			fputs("\nError reading menu option, please try again!\n\n", stdout);
		}
	}


}