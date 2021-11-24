// gausseidel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Please uncoment a code to run it. 
#include <iostream>
#include <cstdio>
#include <time.h>
#include <chrono>

const double matriceLenght = 1000;
int main(){

	//creation of data on heap, because data size of the variable are limited on the stack
	//the compiler complaint about possible data overflow
	int** matrix = new int* [matriceLenght];
	int** matrix2 = new int* [matriceLenght];
	int** matrixResult = new int* [matriceLenght];

	
	for (int f = 0; f < matriceLenght; f++) {
		matrix[f] = new int[matriceLenght];
		matrix2[f] = new int[matriceLenght];
		matrixResult[f] = new int[matriceLenght];
	}
	
	
	for (int j = 0; j < matriceLenght; j++) {
		for (int f = 0; f < matriceLenght; f++){
			matrix[f][j] = 3;
			matrix2[f][j] = 2;
		}
	}
	auto t_start = std::chrono::steady_clock::now();

	//cached version of the computation of two matrices
	/*
	for (int i = 0; i < matriceLenght; i += matriceLenght)
		for (int j = 0; j < matriceLenght; j += matriceLenght)
			for (int k = 0; k < matriceLenght; k += matriceLenght)
				for (int s = 0; s < matriceLenght; ++s)
					for (int t = 0; t < matriceLenght; ++t)
						for (int u = 0; u < matriceLenght; ++u)
							matrixResult[i + s][j + t] += matrix[i + s][k + u] * matrix2[k + u][j + t];
							*/
	
	auto t_end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration<double>(t_end - t_start).count();

	//normal approach to multiply matrices

	for (int i = 0; i < matriceLenght; i++)
		for (int j = 0; j < matriceLenght; j++)
			for (int n = 0; n < matriceLenght; n++)
				matrixResult[i][j] = matrixResult[i][j] + matrix[i][n] * matrix2[n][j];
			
	/*
	for (int y = 0; y < matriceLenght; y++) {
		for (int x = 0; x < matriceLenght; x++) {
			matrixResult[x + y + matriceLenght] += matrix[x][y] * matrix2[x][y];
		}
	}
	*/

					

	


	std::cout << "Time for create two matrices: " << duration << std::endl;
	

	return 0;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
