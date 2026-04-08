#ifndef __SORTING_H__
#define __SORTING_H__

#include <iostream>
#include <string>
#include "types.h"

using namespace std;
using ContainerRange = int;

// Las plantillas (templates) SIEMPRE deben estar en el .h
template <typename T> 
void intercambiar(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> 
void PrintArray(T arr[], ContainerRange n){
    for (auto i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T, typename Func> 
ContainerRange BinarySearch(T arr[], ContainerRange first, ContainerRange last, T elem, Func func){
    if (first > last) return -1;
    auto mid = first + (last - first) / 2;
    if (arr[mid] == elem) return mid;
    if ( func(elem, arr[mid]) )
        return BinarySearch(arr, mid + 1, last, elem, func);
    return BinarySearch(arr, first, mid - 1, elem, func);
}

template <typename T, typename Func> 
void BurbujaClasico(T arr[], ContainerRange n, Func func) {
    if (n <= 1) return;
    for (auto i = 0; i < n - 1; ++i)
        for (auto j = i+1; j < n; ++j)
            if( func(arr[i], arr[j]) )
                intercambiar(arr[i], arr[j]);
}

template <typename T, typename Func> 
void BurbujaRecursivo(T arr[], ContainerRange n, Func func) {
    if (n <= 1) return;
    for (auto j = 1; j < n; ++j)
        if ( func(arr[j], arr[0]) )
            intercambiar(arr[0], arr[j]);
    BurbujaRecursivo(arr+1, n-1, func);
}

// Prototipos de las funciones que están en el .cpp
void DemoBurbuja();
void DemoQuickSort();
void DemoMergeSort();
void DemoSorting();
void DemoSearch();

ContainerRange particionar(T1* arr, ContainerRange first, ContainerRange last, CompFunc pComp);
void QuickSort(T1* arr, ContainerRange first, ContainerRange last, CompFunc pComp);
void Merge(T1* arr, const ContainerRange left, const ContainerRange mid, const ContainerRange right, CompFunc pComp);
void MergeSort(T1* arr, ContainerRange const begin, ContainerRange const end, CompFunc pComp);

#endif // <--- ESTO ES LO QUE LE FALTA A TU ARCHIVO .H