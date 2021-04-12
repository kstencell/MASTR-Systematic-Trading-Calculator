#pragma once

typedef struct indicators {
	float SMA10;
	float SMA25;
	float SMA50;
	float EMA5;
}INDICATORS, *P_INDICATORS;

P_INDICATORS createIndicators();
void computeIndicators(P_DATA_LIST);
float computeSMA(struct dataNode*, int);
float computeEMA(struct dataNode*);
void getPrevNode(struct dataNode*); 

