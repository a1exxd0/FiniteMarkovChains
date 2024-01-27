#include<math.h>
#include<vector>
#include<stdexcept>
#include<string>
#include<cmath>
#include<iostream>

#include "inputs.h"
#include "markov.h"
using std::vector;
using std::endl;
using std::cout;



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

const int N = 3;  // Number of variables

void gaussElimination(double A[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        // Pivot element
        double pivot = A[i][i];

        // Make the pivot element 1
        for (int j = i; j < N + 1; j++) {
            A[i][j] /= pivot;
        }

        // Make other elements in the column zero
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j < N + 1; j++) {
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
}

vector<double> coefficientCalculator3x3(char state1, char state2, double eigenvalues[N]){
    int state1pos;
    int state2pos;
    for (int i = 0; i < 3; i++){
        if (state1 == input1::stateSpace[i]){
            state1pos = i;
        }
        if (state2 == input1::stateSpace[i]){
            state2pos = i;
        }
    }

    double coefficientMatrix[N][N+1];

    coefficientMatrix[0][N] = (state1 == state2) ? 1 : 0;
    coefficientMatrix[1][N] = input1::TM[state1pos][state2pos];
    coefficientMatrix[2][N] = input1::TM[state1pos][0] * input1::TM[0][state2pos]
                + input1::TM[state1pos][1] * input1::TM[1][state2pos]
                + input1::TM[state1pos][2] * input1::TM[2][state2pos];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            coefficientMatrix[i][j] = std::pow(eigenvalues[j], i);
        }
    }

    gaussElimination(coefficientMatrix);
    vector<double> result;
    for (int i = 0; i < N; i++){
        result.push_back(coefficientMatrix[i][N]);
    }
    return result;
}

