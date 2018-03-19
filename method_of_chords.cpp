#include <iostream>
#include <cmath>
#define EPS 1E-6

using namespace std;
double l[2] = {0.0, 5.0};
double equation(double x)
{
	return sqrt(abs(cos(x))) - x;
}
int main()
{
	double (*f)(double) = &equation;
	double x = l[0], x2 = l[1];
	while(abs(x2-x) >EPS)
	{
		x = x2 -(x2-x)*f(x2)/(f(x2) - f(x));
		x2 = x +(x-x2)*f(x) / (f(x) - f(x2));
	}
	cout << "The root of the equation = " << x2 << endl;
	return 0;
}