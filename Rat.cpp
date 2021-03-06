// Rat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
class Rat {
private:
	int n;
	int d;
	int num;
public:
	// constructors

	// default constructor
	Rat() {
		
		n = 0;
		d = 1;
		num = 0;
		
	}

	// 2 parameter constructor
	Rat(int i, int j) {
		
		n = i;
		d = j;
		num = 0;
		
	}
	// conversion constructor
	Rat(int i) {
		//cout << "construct3" << endl;
		n = i;
		d = 1;
		num = 0;
		
	}

	//accessor functions (usually called get() and set(...) )
	int getN() { return n; }
	int getNum() { return num; }
	int getD() { return d; }
	void setN(int i) { n = i; }
	void setNum(int i) { num = i; }
	void setD(int i) { d = i; }

	int getGCD(int a, int b)
	{
		// Everything divides 0  
		if (a == 0)
			return b;
		if (b == 0)
			return a;

		// base case 
		if (a == b)
			return a;

		// a is greater 
		if (a > b)
			return getGCD(a - b, b);
		return getGCD(a, b - a);
	}
	//arithmetic operators


	void mixed(Rat& z)
	{
		
			if (z.num != 0)
			{
				z.n = (z.n + z.num*z.d);
				z.num=0;
			}
		
		bool condition = true;

		while (condition)
		{
			if (z.n >= z.d)
			{
				z.n=(z.n - z.d);
				z.num=((z.num + 1));
				continue;
			}
			condition = false;
		}
		return;
	}

	Rat operator+(Rat r) {
		Rat t;
		t.n = n * r.d + d * r.n;
		t.d = d * r.d;
		int gcd = getGCD(t.n, t.d);
		t.n = t.n / gcd;
		t.d = t.d / gcd;
		mixed(t);
		return t;
	}
	Rat operator-(Rat r) {
		Rat t;
		t.n = n * r.d - d * r.n;
		t.d = d * r.d;
		int gcd = getGCD(t.n,t.d);
		t.n = t.n / gcd;
		t.d = t.d / gcd;
		mixed(t);
		return t;
	}
	Rat operator*(Rat r) {
		Rat t;
		t.n = n * r.n;
		t.d = d * r.d;
		int gcd = getGCD(t.n, t.d);
		t.n = t.n / gcd;
		t.d = t.d / gcd;
		mixed(t);
		return t;
	}
	Rat operator/(Rat r) {
		Rat t;
		t.n = n * r.d;
		t.d = d * r.n;
		int gcd = getGCD(t.n, t.d);
		t.n = t.n / gcd;
		t.d = t.d / gcd;
		mixed(t);
		return t;
	}

	//Rat(const Rat& r) {
	//	cout << "copy constructor" << endl;
	//	n = r.n;
	//	num = r.num;
	//	d = r.d;
	//}

	//Rat& operator=(const Rat& r) {
	//	if (this != &r) {
	//		cout << "= constructor" << endl;
	//		n = r.n;
	//		num = r.num;
	//		d = r.d;
	//	}
	//	return *this;
	//}

		// 2 overloaded i/o operators
		friend ostream& operator<<(ostream& os, Rat r);
	    friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

ostream& operator<<(ostream& os, Rat r) {
	os <<r.num<<"  "<< r.n << " / " << r.d << endl;
	return os;
}

istream& operator>>(istream& is, Rat& r) {
	is >> r.n >> r.d;
	return is;
}


int main() {
	
	
	Rat x(1, 2), y(2, 3), z;
	z = x + y;
	cout << z;


	x.setN(3);
	y.setD(2);
	z = x + y;
	cout << z;

	cout << "Please enter x" << endl;
	cin >> x;
	cout << endl;


	cout <<x;
	z = x + 5;
	cout << z;
	cout << "One more multiply    z = x * 3;" << endl;
	z = x * 3;
	cout << z;
	system("pause");
	return 0;
}
