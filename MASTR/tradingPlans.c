
#include <stdbool.h>
#include <stdio.h>
#include "tradingPlans.h"
#include "mainMenu.h"


void createTradingPlan() {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("~~~~~~~~~~~~~~~ CREATE TRADING PLAN ~~~~~~~~~~~~~~~~~\n", stdout);
	fputs("What would you like to do?\n", stdout);
	fputs("a) Create a systematic trading plan\n", stdout);
	fputs("b) Change your current trading plan\n", stdout);
	fputs("c) Load an existing trading plan from file\n", stdout);

}