#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double getEquation(double x){
    // from x^3+x^2-3x-3

    // to (x^3+x^2 -3) / 3
    // return (pow(x,3)+pow(x,2)-3)/3;

    // to sqrt((3x+3-x^3),2)
    // return sqrt(3*x+3-pow(x,3));

    // to cbrt(3x+3-x^2)
    return cbrt(3*x+3-pow(x,2));
}

int main(){
    double startVal = 2;    
    double toleranceVal = 0.00001;
    cout << fixed << setprecision(5);

    while(abs(startVal-getEquation(startVal)) > toleranceVal){
        startVal = getEquation(startVal);
        cout << startVal << endl;
    }

    return 0;
}