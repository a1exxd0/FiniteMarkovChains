#include <vector>
#include <iostream>
#include "markov.h"

using std::cout;
using std::endl;

int main(){
    for (auto d : calculateinput1::eigenvalues_3){
        cout << "Eigenvalue: " << d << endl;
    }
}