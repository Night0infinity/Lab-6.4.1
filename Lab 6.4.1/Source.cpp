#include <iostream>  
#include <iomanip>  
#include <time.h>  
#include <math.h>
using namespace std;

void random(double* mas, const int size, const double min, const double max, const int i) {
    mas[i] = min + rand() * (max - min) / RAND_MAX;
    if (i < size - 1)
        random(mas, size, min, max, i + 1);
}

void wivid(double* mas, const int size, const int i) {
    if (i < size) {
        cout << setw(6) << mas[i];
        wivid(mas, size, i + 1);
   }
}

double Minpos(double* mas, const int size, int i, int num, double min) {
    if (mas[i] < min)
        min = mas[i];
        num = i;
    if (i < size - 1)
        return Minpos(mas, size, i + 1, num, min);
    else
        return num;
}

double Minnum(double* mas, const int size, int i, double min)
{
    if (mas[i] < min)
        min = mas[i];
    if (i < size - 1)
        return Minnum(mas, size, i + 1, min);
    else
        return min;
}

double poshuk1min(double* mas, const int size, double minus1, int num1, int i)
{
    if (mas[i] < 0) {
        minus1 = mas[i];
        num1 = i;
    }
    if (i < size && mas[i]>=0)
        poshuk1min(mas, size, minus1, num1, i+1);
    else
        return num1;
}

double poshuk2min(double* mas, const int size, double minus2, double m1, int num2, int i)
{
    if (mas[i] < 0) {
        minus2 = mas[i];
        num2 = i;
    }
    if (i < size && mas[i] >= 0)
        poshuk2min(mas, size, minus2, m1,num2,i + 1);
    else
        return num2;
}


double suma(double* mas, int firstminus, int secondminus, int i, double S)
{
    if (i < secondminus) {
        S += mas[i];
        return suma(mas, firstminus, secondminus, i + 1, S);
    }
    else
        return S;
}

void abscent(double* mas, double* secmas, const int size, int& sm, int i) {
   if ( i < size) {
        if (abs(mas[i]) < 1) {
            secmas[sm] = mas[i];
            sm++;
        }
        abscent(mas, secmas, size, sm, i + 1);
    }
}

void abscent2(double* mas, double* thirdmas, const int size, int& tm, int i) {
   if(i < size){
        if (abs(mas[i]) >= 1) {
            thirdmas[tm] = mas[i];
            tm++;
        }
        abscent2(mas, thirdmas, size, tm, i + 1);
    }
}

void abscentcount(double* mas, const int size, int& smm, int i) { // mesha
    if(i < size) {
        if (abs(mas[i]) < 1) {
            smm++;
        }
        abscentcount(mas, size, smm, i + 1);
    }
}

void result1(double* mas, double* secmas, double* d, const int size, int smm, int j, int l, int i) {
    if (i < size) {
        if (i < smm)
            mas[i] = secmas[j++];
        else
            mas[i] = d[l++];
        i++;
        result1(mas, secmas, d, size, smm, j, l, i);
    }
    
}
int main() {

    cout << fixed; cout.precision(2);
    srand((unsigned)time(NULL));
    double min = -5.0;
    double max = 5.0;
    int n;
    cout << "n = "; cin >> n;
    double* b = new double[n];
    double S = 0;
    int k = 0;
    int h = 0;
    int i = 0;
    int np = 0;
    int smm = 0;
    int sm = 0;
    int tm = 0;
    abscentcount(b, n, smm, 0);
    int q = smm;
    double* c = new double[smm];
    double* d = new double[n - smm];
    random(b, n, min, max, 0);
    cout << "Massive :" << endl;
    wivid(b, n, 0);
    cout << endl;
    cout << setw(4) << endl;
    cout << "min position = " << Minpos(b, n, 0, 0, 0) << endl;
    cout << "min number = " << Minnum(b, n, 0, 0) << endl;
    cout << setw(4) << endl;
    cout << "first minus = " << poshuk1min(b, n, k, 0, i) << endl;
    double m1 = poshuk1min(b, n, k, 0, 0);
    cout << "second minus = " << poshuk2min(b, n, h, m1, 0, m1 + 1) << endl;
    double m2 = poshuk2min(b, n, k, m1, 0, m1+1);
    cout << "Suma mish m1 i m2 = " << suma(b, m1, m2, m1+1, 0) << endl;
    cout << endl;
    abscent(b, c, n, sm, 0);
    abscent2(b, d, n, tm, 0);
    int j = 0, l = 0;
    result1(b, c, d, n, sm, j, l, i);
    cout << "Modified massive : " << endl;
    wivid(b, n, 0);
}

