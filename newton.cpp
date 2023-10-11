#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double get_equation(double x){
    return pow(x, 3) - (7*x) + 1;
    // return pow(x,3)+pow(x,2)-(3*x)-3;
}

double diff(double x){
    return 3*pow(x, 2)-7;
    // return 3*pow(x,2)+2*x-3;
}


int main(){
    double a = 1;
    double fA = get_equation(a);
    double diffA = diff(a);
    double toleranceVal = 0;
    cout << fixed << setprecision(5);
    int i = 1;
    while(abs(fA) > toleranceVal){
        cout << a << endl;
        a = a-( fA/diffA);
        fA = get_equation(a);
        diffA = diff(a);
        cout << "nilai fA = " << fA << endl;
        i++;
    }

    cout << a;

    return 0;
}