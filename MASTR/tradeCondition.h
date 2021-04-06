#pragma once

#define BUFFER_SIZE		10

typedef enum conditionStatus { FULL, EMPTY} CONDITION_STATUS;
typedef enum conditionType { BUY, SELL } CONDITION_TYPE;
typedef enum indicatorType { SMA10, SMA25, SMA50 } INDICATOR_TYPE;
typedef enum thresholdType { PERCENTAGE, ABSOLUTE } THRESHOLD_TYPE;
typedef enum thresholdDirection { GREATER_THAN, GREAT_THAN_OR_EQUAL, LESS_THAN, LESS_THAN_OR_EQUAL } THRESHOLD_DIRECTION;

typedef struct tradeCondition {

	//CONDITION_STATUS conditionStatus;
	CONDITION_TYPE conditionType;
	INDICATOR_TYPE indicatorType;
	THRESHOLD_TYPE thresholdType;
	THRESHOLD_DIRECTION thresholdDirection;
	float thresholdValue;
	int shareCount; // amount to trade when condition pops

}TRADE_CONDITION, *P_TRADE_CONDITION;

// PROTOTYPES
P_TRADE_CONDITION initializeTradeCondition();
P_TRADE_CONDITION createTradeCondition();
void selectConditionType(P_TRADE_CONDITION);
void selectIndicatorType(P_TRADE_CONDITION);
void selectThresholdType(P_TRADE_CONDITION);
void selectThresholdDirection(P_TRADE_CONDITION);
void selectThresholdValue(P_TRADE_CONDITION);
double getNumberFromUser();