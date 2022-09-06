#include <iostream>
#include <cmath> //http://www.cplusplus.com/reference/clibrary/cmath/
#include <cstdlib> //https://cplusplus.com/reference/cstdlib/
#include <iomanip> //include setprecision, fixed and get_time //https://cplusplus.com/reference/iomanip/?kw=iomanip
#include <limits>
#include <cstring>  // tools for working with character arrays
#include <cctype> // tools for working with strings isalpha(), toupper, etc
#include <vector>
#include "lab4fn.h"
using namespace std;



void GetMatrixSize(vector<int> &matrixSize) {
	int numRows, numCols;
	cout << "Enter number of rows in this matrix (up to 20) ==> ";
	numRows = ValidateInteger();
	while ((numRows > 20) or (numRows < 1)) {
		cout << "Enter an integer less than 20";
		numRows = ValidateInteger();
	}
	cout << "\nEnter number of columns in this matrix (up to 20) ==> ";
	numCols = ValidateInteger();
	while ((numCols > 20) or (numCols < 1)) {
		cout << "Enter an integer less than 20";
		numRows = ValidateInteger();
	}
		cout << endl;
		matrixSize.at(0) = numRows;
		matrixSize.at(1) = numCols;
}

void BuildMatrix(int(&Matrix)[20][20], vector<int> matrixSize) {
	int i, j;
	cout << "Please enter the values in this matrix, you can enter each row at once, each cell or all of them separated by spaces. \n";
	for (i = 0; i < matrixSize.at(0); i++) {
		for (j = 0; j < matrixSize.at(1); j++) {
			Matrix[i][j] = ValidateInteger();
		}
	}
	StopOverflow();
}

void PrintMatrix(int (&Matrix)[20][20], vector<int> matrixSize) {
	int i, j;
	cout << endl << endl;
	cout << "For this matrix, you entered: \n\n";
	for (i = 0; i < matrixSize.at(0); i++) {
		cout << "|     ";
		for (j = 0; j < matrixSize.at(1); j++) {
			cout << Matrix[i][j] << "     ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

void AddMatrices(int (&matrixOne)[20][20], int (&matrixTwo)[20][20], vector<int> matrixOneSize, vector<int> matrixTwoSize) {
	int i, j;
	if ((matrixOneSize.at(0) != matrixTwoSize.at(0)) or (matrixOneSize.at(1) != matrixTwoSize.at(1))) {
		cout << "Unable to add matrices.  The number or rows and columns must both match." << endl;
	}
	else {
		cout << "The sum of the matrices is: \n";
		for (i = 0; i < matrixOneSize.at(0); i++) {
			cout << "|     ";
			for (j = 0; j < matrixOneSize.at(1); j++) {
				cout << matrixOne[i][j] + matrixTwo[i][j];
				cout << "     ";
			}
			cout << "|" << endl;
		}
	}
	cout << endl;
}

void MultiplyMatrices(int (&matrixOne)[20][20], int (&matrixTwo)[20][20], vector<int> matrixOneSize, vector<int> matrixTwoSize) {
	int i, j, k;
	int indexProduct;

	if ((matrixOneSize.at(0) != matrixTwoSize.at(1)) or (matrixOneSize.at(1) != matrixTwoSize.at(0))) {
		cout << "Unable to multiply matrices.  The number or rows of each must match the columns of the other." << endl;
	}
	else {
		cout << "The product of the matrices is: \n";
		for (i = 0; i < matrixOneSize.at(0); i++) {
			cout << "|     ";
			for (j = 0; j < matrixTwoSize.at(1); j++) {
				indexProduct = 0;
				for (k = 0; k < matrixTwoSize.at(0); k++) {
					indexProduct += matrixOne[i][k] * matrixTwo[k][j];
				}
				cout << indexProduct << "     ";
			}
			cout << "|" << endl;
			}
		}
		cout << endl;

	}

void StopOverflow() {
	char a = 'x';
	while (a != '\n') {
		cin.get(a);
	}
}

int ValidateInteger() {
	double x;
	int y;
	cin >> x;
	while (cin.fail() or (x - int(x) != 0)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Bad entry.  Enter a integer: ";
		cin >> x;
	}
	y = int(x);
	return y;
}

