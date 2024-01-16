#ifndef INPUTS_H
#define INPUTS_H
#define STATESPACESIZE 3

class input1{
    public:
        static double transitionMatrix[STATESPACESIZE][STATESPACESIZE];
        static char stateSpace[STATESPACESIZE];
        static int n;
};


#endif