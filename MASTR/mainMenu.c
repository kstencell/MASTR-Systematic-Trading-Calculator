
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mainMenu.h"
#include "tradeConditionList.h"
#include "historicalData.h"

void printMainMenuOptions() {

	fputs("~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~\n", stdout);
	fputs("What would you like to do?\n", stdout);
	fputs("a) Customize your systematic trading plan\n", stdout);
	fputs("b) Load an existing trading plan from file\n", stdout);
	fputs("c) Save your current trading plan\n", stdout);
	fputs("d) Simulate your trading plan.\n", stdout);
	fputs("e) More Info\n", stdout);
	fputs("f) Quit\n", stdout);
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

		}
		else if (!strcmp("c", userInput)) {

		}
		else if (!strcmp("d", userInput)) {

		}
		else if (!strcmp("e", userInput)) {

		}
		else if (!strcmp("f", userInput)) {
			return false;
		}
		else {
			fputs("\nError reading menu option, please try again!\n\n", stdout);
		}
	}


}