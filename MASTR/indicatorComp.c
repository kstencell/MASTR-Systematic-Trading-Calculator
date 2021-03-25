#include "indicatorComp.h"

double calcMA(/*HDRtailNode,*/ int numDays) {
    int mov_Avg_Val = 0;

    if (numDays = 20) {
        

        for (int i = 0; i < 20; i++) {
            mov_Avg_Val += 1 /*nodeTail->nodeData->close*/; //1 used as dummy;
            getNodePreveNode(/*hdrnode*/);
        }
    }
    if (numDays = 5) {
     
        double smooth_Factor = 2.0, weighted_EMA = 0.0, observed_Days = 5.0, close_Price = 0.0;


        for (int i = 0; i < 5; i++) {
            mov_Avg_Val += 1 /*nodeTail->nodeData->close*/; //1 used as dummy;
            getNodePreveNode(/*hdrnode*/);
        }
         
        weighted_EMA = (smooth_Factor / (observed_Days + 1.0));
        
        
    }
}

double calcTSI(/*""*/) {

}
double calcRSI(/*""*/) {

}
double calcADX(/*""*/) {

}
double calcDMI(/*""*/) {

}

double calcMACD(/*""*/) {

}

void getNodePrevNode(/*hdrnode*/) {
    /* hdrNode = nodeTail->nodeData->prev;*/
    return 0; /*(hdr node)*/
}

void set20SMA(double twentVal, IND comp) {


}
void set5EMA(double fiveVal, IND comp) {

}
void setTSI(double tsiVal, IND comp) {

}
void setMACD(double macd, IND comp) {

}
void setRSI(double rsi, IND comp) {

}
void setADX(double adx, IND comp) {

}
void setDMI(double dmi, IND comp) {

}