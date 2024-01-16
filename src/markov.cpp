#include<inputs.h>
#include<math.h>
#include<vector>
#include<stdexcept>
#define TM input1::transitionMatrix

/*3D usage*/

//first calculate eigenvalues of transition vector

double a_3 = -1;
double b_3 = TM[0][0] + TM[1][1] + TM [2][2];
double c_3 = (TM[2][1] * TM[1][2] + TM[0][1] * TM[1][0] + TM[0][2] * TM[2][0])
    - (TM[0][0] * TM[2][2] + TM[0][0] * TM[1][1] + TM[1][1] * TM[2][2]);
double d_3 = (TM[0][0] * TM[1][1] * TM[2][2]) - (TM[0][0] * TM[1][2] * TM[2][1])
    + (TM[0][2] * TM[1][0] * TM[2][1]) - (TM[0][1] * TM[1][0] * TM[2][2])
    + (TM[0][1] * TM[2][0] * TM[1][2]) - (TM[0][2] * TM[1][1] * TM[2][0]);

std::vector<double> solveCubic(double a, double b, double c, double d) {
    // Discriminant
    double delta0 = b * b - 3 * a * c;
    double delta1 = 2 * b * b * b - 9 * a * b * c + 27 * a * a * d;
    double C = std::cbrt((delta1 + std::sqrt(delta1 * delta1 - 4 * delta0 * delta0 * delta0)) / 2);

    // Check for complex roots
    if (delta1 * delta1 - 4 * delta0 * delta0 * delta0 < 0) {
        throw std::runtime_error("Complex roots detected.");
    }

    // Calculate real roots
    std::vector<double> roots;
    for (int k = 0; k < 3; ++k) {
        double theta = (2.0 * M_PI * k) / 3.0;
        double root = -b / (3.0 * a) - C * std::cos(theta) - (delta0 / (C * std::cos(theta)));
        roots.push_back(root);
    }

    return roots;
}

std::vector<double> eigenvalues_3 = solveCubic(a_3, b_3, c_3, d_3);