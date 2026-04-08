#include "sorting.h" // Asegúrate de que sea .h y no .cpp
#include "util.h"
#include <iostream>

using namespace std;

void DemoSearch(){
    cout << "--- DemoSearch ---" << endl;
    T1 arr1[] = {5, 2, 8, 1, 15, 9, 4, 7, 3, 6};
    auto n1 = (ContainerRange)(sizeof(arr1) / sizeof(arr1[0]));
    BurbujaClasico(arr1, n1, Mayor<T1>);
    PrintArray(arr1, n1);
    cout << "Buscando 5: " << BinarySearch(arr1, 0, n1 - 1, 5, Mayor<T1>) << endl;
    cout << endl;
}

void DemoBurbuja() {
    cout << "--- DemoBurbuja ---" << endl;
    T1 arr1[] = {5, 2, 8, 1, 15, 9, 4, 7, 3, 6};
    auto n1 = (ContainerRange)(sizeof(arr1) / sizeof(arr1[0]));
    PrintArray(arr1, n1);
    BurbujaClasico(arr1, n1, Mayor<T1>);
    PrintArray(arr1, n1);
}

ContainerRange particionar(T1* arr, ContainerRange first, ContainerRange last, CompFunc pComp) {
    auto pivote = arr[last];
    auto i = (first - 1);
    for (auto j = first; j <= last - 1; j++) {
        if ( (*pComp)(arr[j], pivote) ){
            ++i; 
            intercambiar(arr[i], arr[j]);
        }
    }
    intercambiar(arr[i + 1], arr[last]);
    return (i + 1);
}

void QuickSort(T1* arr, ContainerRange first, ContainerRange last, CompFunc pComp) {
    if (first < last) {
        auto pi = particionar(arr, first, last, pComp);
        QuickSort(arr, first, pi - 1, pComp);
        QuickSort(arr, pi + 1, last, pComp);
    }
}

void DemoQuickSort() {
    cout << "--- DemoQuickSort ---" << endl;
    T1 arr[] = {5, 2, 8, 15, 1, 9, 4, 7, 3, 6};
    auto n = (ContainerRange)(sizeof(arr) / sizeof(arr[0]));
    QuickSort(arr, 0, n - 1, Mayor<T1>);
    PrintArray(arr, n);
}

void Merge(T1* arr, const ContainerRange left, const ContainerRange mid, const ContainerRange right, CompFunc pComp) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new T1[subArrayOne];
    auto *rightArray = new T1[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++) leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = arr[mid + 1 + j];

    auto i1 = 0, i2 = 0;
    ContainerRange iM = left;
    while (i1 < subArrayOne && i2 < subArrayTwo) {
        if ( (*pComp)(rightArray[i2], leftArray[i1]) ) {
            arr[iM] = leftArray[i1]; i1++;
        } else {
            arr[iM] = rightArray[i2]; i2++;
        }
        iM++;
    }
    while (i1 < subArrayOne) arr[iM++] = leftArray[i1++];
    while (i2 < subArrayTwo) arr[iM++] = rightArray[i2++];
    delete[] leftArray; delete[] rightArray;
}

void MergeSort(T1* arr, ContainerRange const begin, ContainerRange const end, CompFunc pComp) {
    if (begin >= end) return;
    auto mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid, pComp);
    MergeSort(arr, mid + 1, end, pComp);
    Merge(arr, begin, mid, end, pComp);
}

void DemoMergeSort(){
    cout << "--- DemoMergeSort ---" << endl;
    T1 arr[] = {5, 2, 8, 1};
    auto n = (ContainerRange)(sizeof(arr) / sizeof(arr[0]));
    MergeSort(arr, 0, n - 1, Mayor<T1>);
    PrintArray(arr, n);
}

void DemoSorting() {
    DemoBurbuja();
    DemoQuickSort();
    DemoMergeSort();
}