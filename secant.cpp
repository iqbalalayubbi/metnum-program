#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double getEquation(double x){
    return pow(x,3)+pow(x,2)-(3*x)-3;
    // return pow(x,3)-7*x+1;
}

void printVal(double a, double b, double c, double fA, double fB, double fC){
    cout << "nilai a " << a << endl;
    cout << "nilai b " << b << endl;
    cout << "nilai c " << c << endl;
    cout << "nilai Fa " << fA << endl;
    cout << "nilai Fb " << fB << endl;
    cout << "nilai Fc " << getEquation(c) << endl;
    cout << endl;
}

int main(){
    double a = -3;
    double b = -2;
    double toleranceVal = 0.0001;
    cout << fixed << setprecision(5);

    while(abs(getEquation(b)) > toleranceVal){
        double fA = getEquation(a);
        double fB = getEquation(b);
        double c = b-( (fB*(b-a)) / (fB-fA) );
        printVal(a, b, c, fA, fB, getEquation(c));
        a = b;
        b = c;
    }

    cout << "Akar persamaannya adalah = " << b << endl;

    return 0;
}