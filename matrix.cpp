#include "matrix.h"
#include "sorting.h" 

void CreateMatrix(TP **&pm, const size_t rows, const size_t cols){
    // Creamos la columna vertical morada del dibujo (arreglo de punteros)
    pm = new TP* [rows]; 
    
    // Para cada cajoncito de esa columna, creamos su fila horizontal (cols)
    for (auto i = 0; i < rows; ++i) 
        pm[i] = new TP [cols];
}

// 2. Leer matriz
void ReadMatrix(TP **pm, const size_t rows, const size_t cols){
    cout << "Ingrese " << rows * cols << " valores: ";
    for (auto i = 0; i < rows; ++i)
        for (auto j = 0; j < cols; ++j)
            cin >> pm[i][j];
}

// 3. Imprimir matriz
void PrintMatrix(TP **pm, const size_t rows, const size_t cols){
    for (auto i = 0; i < rows; ++i){
        for (auto j = 0; j < cols; ++j)
            cout << pm[i][j] << "\t";
        cout << endl;
    }
}

// 4. Eliminar matriz (Borrar de adentro hacia afuera)
void DeleteMatrix(TP **&pm, const size_t rows){
    // Primero borramos las filas horizontales moradas
    for (auto i = 0; i < rows; ++i)
        delete[] pm[i];
    
    // Luego borramos la columna vertical
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

    BurbujaClasico(pMat[0], rows * cols, Mayor<TP>);
    PrintMatrix(pMat, rows, cols);
    cout << endl;

    BurbujaClasico(pMat[0], rows * cols, Menor<TP>);
    PrintMatrix(pMat, rows, cols);
    cout << endl;
    
    PrintMatrix(pMat, rows, cols);
    
    DeleteMatrix(pMat, rows);


}