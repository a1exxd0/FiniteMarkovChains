#include <vector>
#include <iostream>
#include "markov.h"
#include "solvers.h"

using std::cout;
using std::endl;
using std::vector;

int main(){
    /*
    cout << "a: " << calculateinput1::a_3 << endl;
    cout << "b: " << calculateinput1::b_3 << endl;
    cout << "c: " << calculateinput1::c_3 << endl;
    cout << "d: " << calculateinput1::d_3 << endl;
    */

    double testarr[4] = {calculateinput1::d_3, calculateinput1::c_3,
                    calculateinput1::b_3, calculateinput1::a_3};

    alglib::real_1d_array arr;
    alglib::complex_1d_array solved;
    alglib::polynomialsolverreport stuff1;
    arr.setlength(4);
    for (int i = 0; i < sizeof(testarr) / sizeof(double); i++){
        arr[i] = testarr[i];
    }
    
    alglib::polynomialsolve(arr, 3, solved, stuff1);

    double eigenvalues[3];
    for(int i = 0; i < solved.length(); i++){
        eigenvalues[i] = solved[i].x;
    }

    vector<double> coef = coefficientCalculator3x3('C', 'C', eigenvalues);
    

    int steps = 10;
    double result = coef[0] * (std::pow(eigenvalues[0], steps))
                    + coef[1] * (std::pow(eigenvalues[1], steps))
                    + coef[2] * (std::pow(eigenvalues[2], steps));

    cout << result << endl;

    for(int i = 0; i < 3; i++){
        printf("coef %d: %lf\n", i, coef[i]);
    }
}