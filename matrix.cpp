#include "matrix.h"
#include "sorting.h" 

void CreateMatrix(TP **&pm, const size_t rows, const size_t cols){
    pm = new TP* [rows];
    for (auto i = 0; i < rows; ++i) 
        pm[i] = new TP [cols];
}

void ReadMatrix(TP **pm, const size_t rows, const size_t cols){
    cout << "Ingrese " << rows * cols << " valores: ";
    for (auto i = 0; i < rows; ++i)
        for (auto j = 0; j < cols; ++j)
            cin >> pm[i][j];
}

void PrintMatrix(TP **pm, const size_t rows, const size_t cols){
    for (auto i = 0; i < rows; ++i){
        for (auto j = 0; j < cols; ++j)
            cout << pm[i][j] << "\t"; 
        cout << endl; 
    }
}

void DeleteMatrix(TP **&pm, const size_t rows){
    for (auto i = 0; i < rows; ++i)
        delete[] pm[i];
    
    delete[] pm;
    pm = nullptr;
}

void DemoMatrix1(){
    size_t rows, cols;
    TP **pMat = nullptr;

    cout << "Demostracion de matrices" << endl;
    cout << "Ingrese nro de filas: ";
    cin >> rows;
    cout << "Ingrese nro de columnas: ";
    cin >> cols;

    CreateMatrix(pMat, rows, cols);
    ReadMatrix(pMat, rows, cols);
    
    // ORDENAR FILA POR FILA
    cout << "\nMatriz ordenada por filas (Mayor):\n";
    for (auto i = 0; i < rows; ++i) {
        BurbujaClasico(pMat[i], cols, Mayor<TP>); 
    }
    PrintMatrix(pMat, rows, cols);
    
    cout << "\nMatriz ordenada por filas (Menor):\n";
    for (auto i = 0; i < rows; ++i) {
        BurbujaClasico(pMat[i], cols, Menor<TP>); 
    }
    PrintMatrix(pMat, rows, cols);
    
    DeleteMatrix(pMat, rows);
}