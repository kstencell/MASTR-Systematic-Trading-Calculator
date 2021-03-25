#include <stdio.h>
#include <math.h>

typedef struct Indicators {

    double twentyDaySMA;
    double fiveDayEMA;
    double fiftyDaySMA;
    double TSI;
    double MACD;
    double RSI;
    double ADX;
    double DMI;

} IND, *P_IND;

void getNodePrevNode(/*hdrnode*/);

double calcMA (/*HDRTailnode*/ int);
double calcTSI(/*""*/);
double calcRSI(/*""*/);
double calcADX(/*""*/);
double calcDMI(/*""*/);
double calcMACD(/*""*/);

void set20SMA(double, IND);
void set5EMA(double, IND);
void setTSI(double, IND);
void setMACD(double, IND);
void setRSI(double, IND); 
void setADX(double, IND);
void setDMI(double, IND);