#include <iostream>
#include <cmath> //http://www.cplusplus.com/reference/clibrary/cmath/
#include <cstdlib> //https://cplusplus.com/reference/cstdlib/
#include <iomanip> //include setprecision, fixed and get_time //https://cplusplus.com/reference/iomanip/?kw=iomanip
#include <limits>
#include <string>
#include <vector>
#include "lab4fn.h"
using namespace std;

int main() {
	vector<int> matrixOneSize(2,0);
	vector<int> matrixTwoSize(2,0);
	int matrixOne[20][20];
	int matrixTwo[20][20];
	bool loop = true;
	char userContinue;


	cout << "__________Welcome to the Matrix Caluclator.__________\n\n\n";


	do {
		cout << "********************** Building matrix one. **********************\n\n";
		GetMatrixSize(matrixOneSize);
		BuildMatrix(matrixOne, matrixOneSize);
		PrintMatrix(matrixOne, matrixOneSize);

		cout << "********************** Building matrix two. **********************\n";
		GetMatrixSize(matrixTwoSize);
		BuildMatrix(matrixTwo, matrixTwoSize);
		PrintMatrix(matrixTwo, matrixTwoSize);
		
		cout << "********************** Adding matrices. **********************\n";
		AddMatrices(matrixOne, matrixTwo, matrixOneSize, matrixTwoSize);
		cout << endl;
		
		
		cout << "********************** Multiplying Matrices. **********************\n";
		MultiplyMatrices(matrixOne, matrixTwo, matrixOneSize, matrixTwoSize);
		cout << endl << endl;
		
		
		cout << "Press \'Q\' to quit.  Any other key to do another grid.";
		cin >> userContinue;
		if (toupper(userContinue) == 'Q') { loop = false; }

	} while (loop);



	return 0;
}

