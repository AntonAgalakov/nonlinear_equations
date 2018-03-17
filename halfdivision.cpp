#include <iostream>
#include <cmath>
#define EPS 1E-6

using namespace std;
double l[2] = {0.0, 5.0};
double equation(double x)
{
	return (pow(x,3)+pow(x,2.5)-2*pow(x,0.5)-2.0);
}
int main()
{
	double (*f)(double) = &equation;
	double x = l[0], x2 = l[1];
	double temp = (x+x2)/2;
	while(abs((*f)(temp)) >EPS)
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
	cout << "The root of the equation = " << temp << endl;
	return 0;
}