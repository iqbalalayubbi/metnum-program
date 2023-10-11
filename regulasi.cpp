#include <iomanip>
#include <iostream>
#include <math.h>

using namespace std;

void printVal(double a, double b, double c, double fA, double fB, double fC){
  cout << "nilai a = " << a << "  ";
  cout << "nilai fA = " << fA << endl;
  
  cout << "nilai b = " << b << "  ";
  cout << "nilai fB = " << fB << endl;
  
  cout << "nilai c = " << c << "  ";
  cout << "nilai fC = " << fC << endl;
  cout << endl;
}

double getEquation(double x) { return pow(x, 2) - x - 2; }

double regulaStep(double a, double b, double toleranceVal) {
  int iterasi = 0;
  double fA = getEquation(a);
  double fB = getEquation(b);
  double c = ((fB * a) - (fA * b)) / (fB - fA);

  double fC = getEquation(c);

  iterasi++;
  cout << "iterasi ke - " << iterasi << endl;
  printVal(a, b, c, fA, fB, fC);

  while (abs(fC) > toleranceVal) {
    if (fA * fC < 0) {
      b = c;
    } else {
      a = c;
    }
    fA = getEquation(a);
    fB = getEquation(b);
    c = ((fB * a) - (fA * b)) / (fB - fA);
    fC = getEquation(c);

    iterasi++;
    cout << "iterasi ke - " << iterasi << endl;
    printVal(a, b, c, fA, fB, fC);
  }

  return c;
}

int main() {
  double a = 1;
  double b = 4;
  double toleranceVal = 0.001;

  if (getEquation(a) * getEquation(b) < 0) {
    cout << fixed << setprecision(5); 

    // ===== regula falsi method =======
    double regulaResult = regulaStep(a, b, toleranceVal);
    cout << "regula falsi method = ";
    cout << regulaResult << endl << endl;

  } else {
    cout << fixed << setprecision(2);
    cout << "tidak dapat menentukan akar penyelesaian diantara " << a << " - " << b;
  }

}
