#pragma once

#define BUFFER_SIZE		5

typedef enum conditionStatus { FULL, EMPTY} CONDITION_STATUS;
typedef enum conditionType { BUY, SELL } CONDITION_TYPE;
typedef enum indicatorType { SMA10, SMA25, SMA50 } INDICATOR_TYPE;
typedef enum thresholdType { PERCENTAGE, ABSOLUTE } THRESHOLD_TYPE;
typedef enum thresholdDirection { GREATER_THAN, GREAT_THAN_OR_EQUAL, LESS_THAN, LESS_THAN_OR_EQUAL } THRESHOLD_DIRECTION;

typedef struct tradeCondition {

	CONDITION_STATUS conditionStatus;
	CONDITION_TYPE conditionType;
	INDICATOR_TYPE indicatorType;
	THRESHOLD_TYPE thresholdType;
	THRESHOLD_DIRECTION thresholdDirection;
	float thresholdValue;

}TRADE_CONDITION, * P_TRADE_CONDITION;


//typedef struct tradingPlan {
//
//	P_TRADE_CONDITION condition1;
//	P_TRADE_CONDITION condition2;
//	P_TRADE_CONDITION condition3;
//	P_TRADE_CONDITION condition4;
//	P_TRADE_CONDITION condition5;
//
//}TRADING_PLAN, *P_TRADING_PLAN;


// PROTOTYPES
P_TRADE_CONDITION initializeTradingPlan();
void createTradingPlan(P_TRADE_CONDITION);
void addTradeCondition(P_TRADE_CONDITION);