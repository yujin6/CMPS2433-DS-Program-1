#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Opens an input file.
ifstream openInputFile();

// Opens an output file.
ofstream openOutputFile();

// Imports values from input file and stores into array.
short importValues(short *b);

// Displays string and exports string into output file.
void output(string s);

// Read each flag from 16 bits value.
void readBits(short b);

int main() {
	short *bits = new short[255];
	short length;

	output("Yujin Yoshimura\n");
	length = importValues(bits);
	for (short i = 0; i < length; i++) {
		output("\nASSIGNMENT #" + to_string(i+1) + " OPTIONS\n");
		readBits(bits[i]);
	}

	delete[] bits;

	system("pause");
	return 0;
}

// Opens an input file.
// @param: none
// @return: ifstream
ifstream openInputFile() {
	string file_name = "bits.dat";
	ifstream myfile(file_name);
	return myfile;
}

// Opens an output file.
// @param: none
// @return: ofstream
ofstream openOutputFile() {
	string file_name = "Yoshimura_Yujin_bits.out";
	ofstream myfile(file_name, ios_base::app);
	return myfile;
}

// Imports values from input file and stores into array.
// @param: short array
// @return: short array (pass by pointer), short
short importValues(short *b) {
	ifstream myfile = openInputFile();
	string line;
	short i = 0;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			b[i] = stoi(line);
			i++;
		}
		myfile.close();
	}
	else { cout << "Unable to open file." << endl; }

	return i;
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

// Read each flag from 16 bits value.
// @param: short
void readBits(short b) {
	if (b & 1) {
		output("This assignment has a time limit.\n");
	}
	if (b & 2) {
		output("The question in this assignment may be printed.\n");
	}
	if (b & 4) {
		output("The questions in this assignment will be scrambled.\n");
	}
	if (b & 8) {
		output("This assignment is password protected.\n");
	}
	if (b & 16) {
		output("Point values for each question will be shown.\n");
	}
	if (b & 32) {
		output("Question titles for each question will be shown.\n");
	}
	if (b & 64) {
		output("This assignment allows access to external links.\n");
	}
	if (b & 128) {
		output("Formulas needed for each question will be shown.\n");
	}
	if (b & 256) {
		output("References for each question will be shown.\n");
	}
	if (b & 512) {
		output("This assignment allows only single attempt.\n");
	}
	if (b & 1024) {
		output("This assignment requires correct letter case.\n");
	}
	if (b & 2048) {
		output("This assignment allows late submissions.\n");
	}
	if (b & 4096) {
		output("This assignment allows access to eBooks.\n");
	}
	if (b & 8192) {
		output("This assignment allows access to \"Check my work\".\n");
	}
	if (b & 16384) {
		output("This assignment requires correct spacing and punctuation.\n");
	}
	if (b & 32768) {
		output("This assignment allows \"Ask the instructor\".\n");
	}
}
