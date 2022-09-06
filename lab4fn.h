#pragma once
#ifndef FILENAME_H
#define FILENAME_H
#include <iostream>
#include <cmath> //http://www.cplusplus.com/reference/clibrary/cmath/
#include <cstdlib> //https://cplusplus.com/reference/cstdlib/
#include <iomanip> //include setprecision, fixed and get_time //https://cplusplus.com/reference/iomanip/?kw=iomanip
#include <limits>
#include <string>
#include <vector>
using namespace std;

void GetMatrixSize(vector<int>& matrixSize);
void BuildMatrix(int(&Matrix)[20][20], vector<int> matrixSize);
void PrintMatrix(int(&Matrix)[20][20], vector<int> matrixSize);
void AddMatrices(int (&matrixOne)[20][20], int (&matrixTwo)[20][20], vector<int> matrixOneSize, vector<int> matrixTwoSize);
void MultiplyMatrices(int(&matrixOne)[20][20], int(&matrixTwo)[20][20], vector<int> matrixOneSize, vector<int> matrixTwoSize);
int ValidateInteger();
void StopOverflow();

#endif