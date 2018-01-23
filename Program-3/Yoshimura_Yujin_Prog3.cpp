/**
* This program calculates permutation and combination by both recursion and non-recursion.
* @version 1.0 2017-11-08
* @course CMPS2433 Dr. Wuthrich
* @author Yujin Yoshimura
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// Solves factorial using recursion.
double factRec(double x);

// Solves factorial without using recursion.
double factIter(double x);

int main() {
	string line;
	double n, r, p, c;
	char type;

	ifstream myinfile("combo.dat");
	ofstream myoutfile("Yoshimura_Yujin_Prog3.txt");

	if (myinfile.is_open()) {
		if (myoutfile.is_open()) {
			cout << "Yujin Yoshimura\n";
			myoutfile << "Yujin Yoshimura\n";
		}
		else { cout << "Unable to open file." << endl; }
		while (getline(myinfile, line)) {
			stringstream stream(line);
			while (true) {
				stream >> type >> n >> r;
				if (!stream) { break; }
			}
			if (type == 'P' || type == 'p') {
				p = factRec(n) / factRec(n - r);
				if (myoutfile.is_open()) {
					cout << setprecision(0) << fixed << p << endl;
					myoutfile << setprecision(0) << fixed << p << endl;
				}
				else { cout << "Unable to open file." << endl; }
			}
			if (type == 'C' || type == 'c') {
				c = factIter(n) / (factIter(n - r) * factIter(r));
				if (myoutfile.is_open()) {
					cout << setprecision(0) << fixed << c << endl;
					myoutfile << setprecision(0) << fixed << c << endl;
				}
				else { cout << "Unable to open file." << endl; }
			}
		}
		myoutfile.close();
		myinfile.close();
	}
	else { cout << "Unable to open file." << endl; }

	system("pause");
	return 0;
}

// Solves factorial using recursion.
// @param: int that defines factorial.
// @return: int
double factRec(double x) {
	if (x == 0) {
		return 1;
	}
	else {
		return x * factRec(x - 1);
	}
}

// Solves factorial without using recursion.
// @param: int that defines factorial.
// @return: int
double factIter(double x) {
	double product = 1;
	for (double i = x; i > 0; i--) {
		product = product * i;
	}
	return product;
}
