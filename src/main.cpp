#include <vector>
#include <iostream>
#include "markov.h"
#include "solvers.h"

using std::cout;
using std::endl;

int main(){
    cout << "a: " << calculateinput1::a_3 << endl;
    cout << "b: " << calculateinput1::b_3 << endl;
    cout << "c: " << calculateinput1::c_3 << endl;
    cout << "d: " << calculateinput1::d_3 << endl;

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
    for(int i = 0; i < solved.length(); i++){
        cout << solved[i].x << endl;
    }
}