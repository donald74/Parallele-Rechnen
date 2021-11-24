// Vectorization.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
#include <iostream>
#include <cstdio>
#include <time.h>
#include <chrono>
//the compiler complain for possible stack overflow when the value reach 300
const int matriceLenght = 280;
int main(int argc, char* argv[]) {
	
	//creation of 2 dimentional matrices
	int matrix[matriceLenght][matriceLenght];
	int  matrix2[matriceLenght][matriceLenght];
	int matrixResult[matriceLenght][matriceLenght];
	
	//add some data into the matrices
	auto t_start = std::chrono::steady_clock::now();
	for (int j = 0; j < matriceLenght; j++)
		for (int f = 0; f < matriceLenght; f++){
			matrix[f][j] = 2;
			matrix2[f][j] = 3;
			matrixResult[f][j] = 0;
		}
	//print both matrices 1 and 2
	/*
	for (int i = 0; i < matriceLenght; i++)
	{
		for (int f = 0; f < matriceLenght; f++){
			std::cout << matrix2[f][i];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < matriceLenght; i++)
	{
		for (int f = 0; f < matriceLenght; f++) {
			std::cout << matrix[f][i];
		}
		std::cout << std::endl;
	}
	*/
//Multiplication of both matrices
	 /*
	for (int i = 0; i < matriceLenght; i++)
			for (int j = 0; j < matriceLenght; j++)
				for (int n = 0; n < matriceLenght; n++)
				matrixResult[i][j] = matrixResult[i][j]+ matrix[i][n] * matrix2[n][j];
		*/
	
//cahed version of computation
	
	for (int i = 0; i < matriceLenght; i += matriceLenght)
		 for (int j = 0; j < matriceLenght; j += matriceLenght)
		for (int k = 0; k < matriceLenght; k += matriceLenght)
			 for (int s = 0; s < matriceLenght; ++s)
			for (int t = 0; t < matriceLenght; ++t)
				 for (int u = 0; u < matriceLenght; ++u)
					 matrixResult[i + s][j + t] += matrix[i + s][k + u] * matrix2[k + u][j + t];
		
					 
			
//display the result
	/*
	std::cout <<"The result is : " << std::endl;
	for (int i = 0; i < matriceLenght; i++)
	{
		for (int f = 0; f < matriceLenght; f++) {
			std::cout << matrixResult[f][i] <<" ";
		}
		std::cout << std::endl;
	}
	*/
	
	

	auto t_end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration<double>(t_end - t_start).count();
	
	
	std::cout << "Time for multiplication two matrices: " << duration << std::endl;
	return 0;
}