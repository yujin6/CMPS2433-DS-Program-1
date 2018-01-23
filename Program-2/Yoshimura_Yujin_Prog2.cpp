/**
* This program calculates linear difference equation by both recursion and non-recursion.
* @version 1.0 2017-10-18
* @course CMPS2433 Dr. Wuthrich
* @author Yujin Yoshimura
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

// Opens an input file.
ifstream openInputFile();

// Opens an output file.
ofstream openOutputFile();

// Displays string and exports string into output file.
void output(string s);

// Imports values from an input file into an array.
int importFile(string *lines);

// Parse a line of string into integers.
void parseValues(string line, int &k, int &m, int &a0, int &n);

// Solves linear difference equation using recursion.
int recursion(int k, int m, int a0, int n);

// Solves linear difference equation without using recursion.
int nonrecursion(int k, int m, int a0, int n);

int main() {
	string lines[255];
	int length, k, m, a0, n, an;

	output("Yujin Yoshimura\n");

	length = importFile(lines);
	for (int i = 0; i < length; i++) {
		parseValues(lines[i], k, m, a0, n);
		output("\nEquation #" + to_string(i + 1) + "\n\n");
		an = recursion(k, m, a0, n);
		output("The " + to_string(n) + "th term found using the recursive solution is : ");
		output(to_string(an) + "\n");
		an = nonrecursion(k, m, a0, n);
		output("The " + to_string(n) + "th term found using the non-recursive solution is : ");
		output(to_string(an) + "\n");
	}
	system("pause");
	return 0;
}

// Opens an input file.
// @param: none
// @return: ifstream
ifstream openInputFile() {
	string file_name = "recur.dat";
	ifstream myfile(file_name);
	return myfile;
}

// Opens an output file.
// @param: none
// @return: ofstream
ofstream openOutputFile() {
	string file_name = "Yoshimura_Yujin_recur.out";
	ofstream myfile(file_name, ios_base::app);
	return myfile;
}

// Displays string and exports string into output file.
// @param: string
void output(string s) {
	ofstream myfile = openOutputFile();

	if (myfile.is_open()) {
		cout << s;
		myfile << s;
		myfile.close();
	}
	else { cout << "Unable to open file." << endl; }
}

// Imports values from an input file into an array.
// @param: array of string
// @return: void (pass by pointer)
int importFile(string *lines) {
	int k, m, a0, n;
	int i = 0;
	string line;

	ifstream myfile = openInputFile();
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			lines[i] = line;
			i++;
		}
		myfile.close();
	}
	else { cout << "Unable to open file." << endl; }

	return i;
}

// Parse a line of string into integers.
// @param: string to be parsed, 4 int that return parsed values
// @return: void (pass by reference)
void parseValues(string line, int &k, int &m, int &a0, int &n) {
	stringstream stream(line);
	while (true) {
		stream >> k >> m >> a0 >> n;
		if (!stream) { break; }
	}
}

// Solves linear difference equation using recursion.
// an = ka(n-1)+m, with initial value a0
// @param: 4 int that defines linear difference equation.
// @return: int
int recursion(int k, int m, int a0, int n) {
	if (n == 0) {
		return a0;
	}
	else {
		return k * recursion(k, m, a0, n - 1) + m;
	}
}

// Solves linear difference equation without using recursion.
// an = ka(n-1)+m, with initial value a0
// @param: 4 int that defines linear difference equation.
// @return: int
int nonrecursion(int k, int m, int a0, int n) {
	int an, c;
	if (k != 1) {
		c = m / (k - 1);
		an = (pow(k, n) * (a0 + c)) - c;
	}
	else {
		an = a0 + (m * n);
	}
	return an;
}
