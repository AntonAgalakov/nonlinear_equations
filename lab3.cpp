#include <iostream>
#include <cmath>
#include "lab3.h"
#define EPS 1E-6

using namespace std;
double l[2] = {0.0, 5.0};
double halfvision(double x, double x2, double (*f)(double))
{
	double temp = (x+x2)/2;
	while(abs(x2-x) > EPS)
	{
		if((*f)(temp) < 0 && (*f)(x) > 0)
			x2 = temp;
		else if((*f)(temp) > 0 && (*f)(x2) < 0)
			x = temp;
		else if ((*f)(temp) > 0 && (*f)(x) < 0)
			x2 = temp;
		else if((*f)(temp)< 0 && (*f)(x2) > 0)
			x = temp;
		temp = (x + x2) / 2;
	}
	return temp;
}
double chords(double x, double x2, double (*f)(double))
{
	while(abs(x2-x) > EPS)
	{
		x = x2 -(x2-x)*f(x2)/(f(x2) - f(x));
		x2 = x +(x-x2)*f(x) / (f(x) - f(x2));
	}
	return x2;
}
double Nuton(double x, double x2, double (*f)(double), double (*df)(double))
{
	while(abs(x2-x) > EPS)
	{
		x = x2;
		x2 = x -(f(x)/df(x));
	}
	return x2;
}
int main()
{
	double (*f)(double) = &equation2;
	double (*df)(double) = &dequation2;
	cout << "The root of the equation = " << halfvision(l[0], l[1], f) << endl;
	cout << "The root of the equation = " << chords(l[0], l[1], f) << endl;
	cout << "The root of the equation = " << Nuton(l[0], l[1], f, df) << endl;
	return 0;
}