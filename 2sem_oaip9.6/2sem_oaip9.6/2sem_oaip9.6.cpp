#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

double fun(double x)
{
    return log(x) - 5 * pow(sin(x), 2);
}


double Metod1(double x0, double x1, double eps) {
    double y0, y1, x2, de;
    y0 = fun(x0);	   y1 = fun(x1);
    do {
        x2 = x1 - y1 * (x1 - x0) / (y1 - y0);
        de = fabs(x1 - x2);
        x0 = x1; 	x1 = x2; 	y0 = y1; 	y1 = fun(x2);
    } while (de > eps);
    return x2;	    // Возвращаем значение, для которого достигнута точность
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    
    double a = 2, b = 6;
    double h = 0.1, eps = 0.001;

    double ans[3];
    int nom = 0;
    for (double x = a; x < b; x += h) {
        if (fun(x) * fun(x + h) < 0) {
            ans[nom] = Metod1(x, x + h, eps);
            nom++;
        }
    }
    for (double x : ans) {
        cout << "Корень = " << x << "\t" << "Значение =  " << fun(x) <<  endl;
    }
}


