#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// fungsi utama x*x-x-2
double getEquation(double x)
{
  return x * x - x - 2;
}

int isDivergen(double a, double b)
{
  return getEquation(a) * getEquation(b) > 0;
}

double bisectionMethod(double a, double b, double tol)
{
  double c;
  int iter = 0;

  do
  {
    c = (a + b) / 2;
    double fA = getEquation(a);
    double fC = getEquation(c);

    if (fA * fC < 0)
      b = c;
    else
      a = c;
    iter++;

    cout << "Iterasi " << iter << ": x = " << c << " \t| Error = " << setprecision(6) << abs(getEquation(c)) << endl;

  } while (abs(getEquation(c)) > tol);

  return c;
}

double regulaFalsiMethod(double a, double b, double tol)
{
  double c;
  int iter = 0;

  do
  {
    double fA = getEquation(a);
    double fB = getEquation(b);
    c = (a * fB - b * fA) / (fB - fA);

    double fC = getEquation(c);

    if (fA * fC < 0)
      b = c;
    else
      a = c;
    iter++;

    cout << "Iterasi " << iter << ": x = " << c << " \t| Error = " << setprecision(6) << abs(getEquation(c)) << endl;

  } while (abs(getEquation(c)) > tol);

  return c;
}

double secantMethod(double a, double b, double tol)
{
  double x0 = a, x1 = b;
  double x2;
  int iter = 0;
  double err;

  do
  {
    double fa = getEquation(x0);
    double fb = getEquation(x1);
    // b-( (fB*(b-a)) / (fB-fA) );
    x2 = x1 - ((fb * (x1 - x0)) / (fb - fa));
    iter++;

    if (iter == 1)
    {
      err = abs(getEquation(x2));
    }
    else
    {
      if (abs(getEquation(x2)) > err)
      {
        cout << err << endl;
        cout << abs(getEquation(x2)) << endl;
        cout << "Akar tidak ditemukan" << endl;
        break;
      }
    }
    if (isnan(abs(getEquation(x2))))
    {
      cout << "Akar tidak ditemukan";
      break;
    }
    else
    {
      cout << "Iterasi " << iter << ": x = " << x2 << " \t| Error = " << setprecision(6) << abs(getEquation(x2)) << endl;
    }
    x0 = x1;
    x1 = x2;
  } while (abs(getEquation(x2)) > tol);

  return x2;
}

double newtonRaphsonMethod(double a, double tol)
{
  double x = a;
  int iter = 0;
  double err;
  do
  {
    double fX = getEquation(x);
    double fXPrime = 2 * x - 1;
    x = x - (fX / fXPrime);
    iter++;
    if (iter == 1)
    {
      err = abs(getEquation(x));
    }
    else
    {
      if (abs(getEquation(x)) > err)
      {
        cout << "Akar tidak ditemukan" << endl;
        break;
      }
    }
    cout << "Iterasi " << iter << ": x = " << x << " \t| Error = " << setprecision(6) << abs(getEquation(x)) << endl;
    err = abs(getEquation(x));
  } while (abs(getEquation(x)) > tol);

  return x;
}

double iteratioEquation(int choice, double x)
{
  switch (choice)
  {
  case 1:
    return x * x - 2;
    break;
  case 2:
    return sqrt(x + 2);
    break;
  default:
    return 2 / (x - 1);
    break;
  }
}

double openMethod(double a, double tol, int choice)
{
  double x = a;
  double err;
  int iter = 0;
  double startVal = x;

  while (abs((x - iteratioEquation(choice, x)) / iteratioEquation(choice, x) * 100) > tol && iter <= 10)
  {
    iter++;
    x = iteratioEquation(choice, x);
    if (iter == 1)
    {
      err = abs((x - iteratioEquation(choice, x)) / iteratioEquation(choice, x) * 100);
    }
    else
    {
      if (abs(iteratioEquation(choice, x)) > err)
      {
        cout << "akar tidak ditemukan" << endl;
        return 0;
        break;
      }
    }
    err = abs((x - iteratioEquation(choice, x)) / iteratioEquation(choice, x) * 100);
    cout << "Iterasi " << iter << ": x = " << x << " \t| Error = " << setprecision(6) << err << endl;
  }

  return x;
}

int main()
{
  double a, b, tolerance;
  int choice;

  double secantRoot = 0, bisectionRoot = 0, regulaRoot = 0, newtonRoot = 0, openRoot = 0;

  cout << "Pilih metode untuk mencari akar fungsi x^2 - x - 2:" << endl;
  cout << "1. Metode Bisection" << endl;
  cout << "2. Metode Regula Falsi" << endl;
  cout << "3. Metode Newton-Raphson" << endl;
  cout << "4. Metode Secant" << endl;
  cout << "5. Metode Iteasi Titik Tetap" << endl;
  cout << "Pilihan Anda: ";
  cin >> choice;

  switch (choice)
  {
  // bisection
  case 1:
    cout << "Masukkan batas bawah dan atas (a dan b): ";
    cin >> a >> b;
    while (isDivergen(a, b))
    {
      cout << "tidak dapat menemukan akar penyelesaian diantara " << a << " sampai " << b << endl;
      cout << "Coba Nilai Lainnya (a dan b): ";
      cin >> a >> b;
    }
    cout << "Masukkan toleransi error: ";
    cin >> tolerance;
    bisectionRoot = bisectionMethod(a, b, tolerance);
    cout << "Akar penyelesaian (Bisection): " << bisectionRoot << endl;
    break;
  // Regula falsi
  case 2:
    cout << "Masukkan batas bawah dan atas (a dan b): ";
    cin >> a >> b;
    while (isDivergen(a, b))
    {
      cout << "tidak dapat menemukan akar penyelesaian diantara " << a << " sampai " << b << endl;
      cout << "Coba Nilai Lainnya (a dan b): ";
      cin >> a >> b;
    }
    cout << "Masukkan toleransi error: ";
    cin >> tolerance;
    regulaRoot = regulaFalsiMethod(a, b, tolerance);
    cout << "Akar penyelesaian (Regula Falsi): " << regulaRoot << endl;
    break;

  // newton
  case 3:
    cout << "Masukkan tebakan awal: ";
    cin >> a;
    cout << "Masukkan toleransi error: ";
    cin >> tolerance;
    newtonRoot = newtonRaphsonMethod(a, tolerance);
    if (abs(getEquation(newtonRoot)) <= abs(getEquation(a)))
    {
      cout << "Akar penyelesaian (Newton Rapshon): " << newtonRoot << endl;
    }
    break;
  // secant
  case 4:
    cout << "Masukkan dua tebakan awal (a dan b): ";
    cin >> a >> b;
    cout << "Masukkan toleransi error: ";
    cin >> tolerance;
    secantRoot = secantMethod(a, b, tolerance);
    if (abs(getEquation(secantRoot)) <= abs(getEquation(a)))
    {
      cout << "Akar penyelesaian (Secant): " << secantRoot << endl;
    }
    break;
  // iterasi terbuka
  case 5:
    int option;
    cout << "Pilih persamaan baru g(x)" << endl;
    cout << "1. x * x - 2" << endl;
    cout << "2. sqrt(x + 2)" << endl;
    cout << "3. 2 / (x - 1)" << endl;
    cout << "Masukkan pilihan : ";
    cin >> option;
    cout << "Masukkan Nilai Tebakan x : ";
    cin >> a;
    cout << "Masukkan toleransi error: ";
    cin >> tolerance;
    openRoot = openMethod(a, tolerance, option);
    if (openRoot != 0)
    {
      cout << "Akar penyelesaian (Iterasi Terbuka): " << openRoot << endl;
    }
    break;
  default:
    cout << "Pilihan tidak valid." << endl;
  }

  return 0;
}
