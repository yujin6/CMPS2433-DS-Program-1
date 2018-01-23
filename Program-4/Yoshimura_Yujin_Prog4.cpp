/**
* This program analyzes adjacency matrix and interprets it as simple undirected graph.
* @version 1.0 2017-12-06
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

int main() {
	string line;
	int** matrix;
	int max_matrix, size, edge, deg, total_deg;
	char vertex;
	bool adj;

	ifstream myinfile("adj.dat");
	ofstream myoutfile("Yoshimura_Yujin_adj.txt");

	if (myinfile.is_open()) {
		if (myoutfile.is_open()) {
			cout << "Yujin Yoshimura\n";
			myoutfile << "Yujin Yoshimura\n";
		}
		else { cout << "Unable to open file." << endl; }
		getline(myinfile, line);
		max_matrix = stoi(line);
		for (int matrix_no = 1; matrix_no <= max_matrix; matrix_no++) {
			cout << "Matrix " + to_string(matrix_no) + "\n";
			myoutfile << "Matrix " + to_string(matrix_no) + "\n";
			getline(myinfile, line);
			size = stoi(line);
			matrix = new int*[size];
			for (int i = 0; i < size; i++) {
				matrix[i] = new int[size];
				getline(myinfile, line);
				stringstream stream(line); 
				for (int j = 0; j < size; j++) {
					stream >> edge;
					matrix[i][j] = edge;
				}
			}
			adj = true;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (i == j) {
						if (matrix[i][j] != 0)
							adj = false;
					}
					else {
						if (matrix[i][j] != matrix[j][i])
							adj = false;
						if (matrix[i][j] > 1)
							adj = false;
					}
				}
			}
			if (adj) {
				cout << "Degree of:\n";
				myoutfile << "Degree of:\n";
				total_deg = 0;
				for (int i = 0; i < size; i++) {
					vertex = static_cast<char>(i + 65);
					stringstream stream("");
					deg = 0;
					for (int j = 0; j < size; j++) {
						deg = deg + matrix[i][j];
					}
					total_deg = total_deg + deg;
					stream << "Vertex " << vertex << ": " << deg << "\n";
					cout << stream.str();
					myoutfile << stream.str();
				}
				cout << "Number of edges: " + to_string(total_deg / 2) + "\n\n";
				myoutfile << "Number of edges: " + to_string(total_deg / 2) + "\n\n";
			}
			else {
				cout << "INVALID\n\n";
				myoutfile << "INVALID\n\n";
			}
			for (int i = 0; i < size; i++) {
				delete[] matrix[i];
				matrix[i] = nullptr;
			}
			delete[] matrix;
			matrix = nullptr;
		}
		myoutfile.close();
		myinfile.close();
	}
	else { cout << "Unable to open file." << endl; }

	system("pause");
	return 0;
}