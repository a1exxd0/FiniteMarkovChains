#include<math.h>
#include<vector>
#include<stdexcept>

#include "inputs.h"
#include "markov.h"
#include "solvers.h"


#define TM input1::transitionMatrix

/*3D usage*/

//first calculate eigenvalues of transition vector

double calculateinput1::a_3 = -1;
double calculateinput1::b_3 = TM[0][0] + TM[1][1] + TM [2][2];
double calculateinput1::c_3 = (TM[2][1] * TM[1][2] + TM[0][1] * TM[1][0] + TM[0][2] * TM[2][0])
    - (TM[0][0] * TM[2][2] + TM[0][0] * TM[1][1] + TM[1][1] * TM[2][2]);
double calculateinput1::d_3 = (TM[0][0] * (TM[1][1] * TM[2][2] - TM[2][1] * TM[1][2]))
    - (TM[0][1] * (TM[1][0] * TM[2][2] - TM[2][0] * TM[1][2]))
    + (TM[0][2] * (TM[1][0] * TM[2][1] - TM[2][0] * TM[1][1]));

bool isCloseToZero(double value, double tolerance = 1e-10) {
    return std::fabs(value) < tolerance;
}



std::vector<double> calculateinput1::eigenvalues_3 = calculateinput1::solveCubic(1,-2,0,20);


//calculateinput1::solveCubic
//        (calculateinput1::a_3, calculateinput1::b_3, calculateinput1::c_3, calculateinput1::d_3);