#include <inputs.h>


/*Input 1 */
double input1::transitionMatrix[STATESPACESIZE][STATESPACESIZE] = 
    {
        {0.3, 0.5, 0.2},
        {0.1, 0.6, 0.3},
        {0.1, 0.1, 0.8}
    };

char input1::stateSpace[STATESPACESIZE] =
    {'A', 'B', 'C'};


