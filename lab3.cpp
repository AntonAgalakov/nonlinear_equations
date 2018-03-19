#include <iostream>
#include <cmath>
#define EPS 1E-6

using namespace std;
double l[2] = {0.0, 5.0};
double equation(double x)
{
	return sqrt(abs(cos(x))) - x;
}

double halfvision(double x, double x2, double (*f)(double))
{
	double temp = (x+x2)/2;
	while(abs((*f)(temp)) > EPS)
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
	while(abs(x2-x) >EPS)
	{
		x = x2 -(x2-x)*f(x2)/(f(x2) - f(x));
		x2 = x +(x-x2)*f(x) / (f(x) - f(x2));
	}
	return x2;
}
int main()
{
	double (*f)(double) = &equation;
	cout << "The root of the equation = " << halfvision(l[0], l[1], f) << endl;
	cout << "The root of the equation = " << chords(l[0], l[1], f) << endl;
	return 0;
}