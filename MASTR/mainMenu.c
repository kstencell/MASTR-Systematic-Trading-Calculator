
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mainMenu.h"

void mainMenu() {

	char userInput[MAX_USER_INPUT_LEN];
	bool validOptionChoice = false;

	fputs("~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~\n", stdout);
	fputs("What would you like to do?\n", stdout);
	fputs("a) Create a systematic trading plan\n", stdout);
	fputs("b) Change your current trading plan\n", stdout);
	fputs("c) Load an existing trading plan from file\n", stdout);
	fputs("d) Save your current trading plan\n", stdout);
	fputs("e) Simulate your trading plan.\n", stdout);
	fputs("f) More Info\n", stdout);
	fputs("g) Quit\n", stdout);
	fputs("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n", stdout);
	fputs("Option: ", stdout);

	while (!validOptionChoice) {
		fgets(userInput, MAX_USER_INPUT_LEN, stdin);
		userInput[strcspn(userInput, "\n")] = 0; // removes the newline char from user input

		if (!strcmp("a", userInput)) {

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

		}
		else {
			fputs("\nError reading menu option, please try again!\n\n", stdout);
		}
	}


}