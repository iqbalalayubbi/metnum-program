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
    // return cbrt(3*x+3-pow(x,2));

    return x*x-2;
    // return sqrt(x+2);
    // return 2/(x-1);
}

int main(){
    // divergen ketika eror lebih besar daripada nilai sebelumnya
    double startVal = 0;    
    double toleranceVal = 0.001;
    cout << fixed << setprecision(5);

    while(abs((startVal-getEquation(startVal))/getEquation(startVal)*100) > toleranceVal){
        cout << abs((startVal-getEquation(startVal))/getEquation(startVal)*100) << endl;
        startVal = getEquation(startVal);
    }

    return 0;
}