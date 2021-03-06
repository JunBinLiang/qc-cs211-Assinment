// integral junbin.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
using namespace std;
typedef double(*FUNC)(double);


double line(double x) {
	return x;
}

double square(double x) {
	return x * x;
}

double cube(double x) {
	return x * x*x;
}

double integrate(FUNC f, double a, double b) 
{
	
	int segment = 100;
	double deltaX = (b - a) / segment;  //0.04 width
	double sum = 0;
	double midpoint;
	midpoint = ((a + deltaX)+a) / 2;      

	//cout << midpoint << endl;
	for (int i=0; i < segment; i++) 
	{
	    
		sum = sum + f(midpoint)*deltaX;
		midpoint += deltaX;
	}

	return sum;
}



int main()
{
	cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
	cout << "The integral of f(x) = x ^ 2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
	cout << "The integral of f(x) = x ^ 3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
}

