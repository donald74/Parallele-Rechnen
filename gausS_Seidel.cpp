// gaussSeidel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;
const int matriceLenght = 2;
const int numberOfIteration = 4;
int main()
{
    // table for all the data used for computation
    double** arrayGaus = new double*[matriceLenght];
    double* sideValue = new double[matriceLenght];
    double* intialValue = new double[matriceLenght];
    double* tempGauss = new double[10];

    for (int y = 0; y < matriceLenght; y++) {
        arrayGaus[y] = new double[matriceLenght];
    }

    //value initialisation
    for (int i = 0; i < matriceLenght; i++) {
        for (int j = 0; j < matriceLenght; j++) {
            arrayGaus[j][i] = 2;
            tempGauss[j] = 0;
        }
    }

    for (int i = 0; i < matriceLenght; i++) {
        intialValue[i] = 0;
    }
    for (int i = 0; i < matriceLenght; i++)
       sideValue[i] = 3;
    //Gauss Seidel computation
    for (int j = 0; j < numberOfIteration; j++) {
        for (int i = 0; i < matriceLenght; i++) {
            //tempGauss[i] = sideValue[i] / arrayGaus[i][i];
            for (int k = 0; k < matriceLenght; k++) {
                //tempGauss[i] = tempGauss[i] - ((arrayGaus[i][k] / arrayGaus[i][j] * intialValue[k]));
                tempGauss[i] = (sideValue[i] / arrayGaus[i][i]) - ((arrayGaus[i][k] / arrayGaus[i][j] * intialValue[k]));
                intialValue[i] = tempGauss[i];
            }
            std::cout << "x" << j << " = " << tempGauss[j] << " ";
        }
        cout << "\n";
    }
    //free allocated memory
    for (int i = 0; i < matriceLenght; i++) 
        delete[] arrayGaus[i];
    
    
    

    
    return 0;
}
