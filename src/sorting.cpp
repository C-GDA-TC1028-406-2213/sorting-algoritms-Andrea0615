#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace SortingAlgorithms {

void bubbleSort(int arr[], int n) {
    int temp;
    // Recorremos hasta n-1 pasadas
    for (int i = 0; i < n - 1; i++) {
        // Comparamos hasta el penúltimo elemento válido
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                /*swap*/
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    int p;
    int min;
    for(int i=0; i<n-1;i++){
        min=arr[i];
        p=i;
        for (int j=i+1;j<n;j++){
            if (min>arr[j]){
                min=arr[j];
                p=j; 
            }
        }
        int temp=arr[i];
        arr[i]=arr[p];
        arr[p]=temp;

    }
    
}

void insertionSort(int arr[], int n) {
    /*Donde almacenar la posicion*/
    int pos;
    int temp; /*Para poder hacer el cambio de los nums*/

    for(int i=0; i<n; i++){
        pos=i; /*quiero que vaya avanzando conforme al bucle*/
        /*en que numero voy de mi array?*/
        temp=arr[i];/*Voy guardando mi num temporalmente*/
        while((pos>0)&& (arr[pos-1]>temp)){/*el de la iquierda es menor que el actual?*/
            arr[pos]=arr[pos-1];/*Hacer el intercambio*/
            pos= pos-1;
        }
        arr[pos]=temp;
    }
    
}

void merge(int arr[], int left, int mid, int right) {
        int p1=left;
    int p2=mid+1;
    int num_elem= right - left + 1;     // número de elementos en el rango
    int* temp_arr= new int[num_elem];
    int i=0;

    while((p1<=mid) &&(p2<=right)){
        if (arr[p1]<arr[p2]){
            temp_arr[i]=arr[p1];
            i++;
            p1= p1+1;
        }else{
          temp_arr[i]=arr[p2];
          i++;
          p2= p2+1;
          }
    }
    while (p1<=mid){
        temp_arr[i]=arr[p1];
        i++;
        p1= p1+1;
    }
    while (p2<=right){
        temp_arr[i]=arr[p2];
        i++;
        p2= p2+1;  
    }
    for (int k = 0; k < num_elem; k++) {
        arr[left + k] = temp_arr[k];
    }
    delete[]temp_arr;
}

void mergeSort(int arr[], int left, int right) {
  if (left < right){
    int mid= (left + right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid +1,right);
    merge(arr,left, mid, right);
  }   
}
int partition(int arr[], int low, int high) {
    int piv = arr[low];
    int i = low;
    int j = high + 1;

    while (i<j){
        do {
            i++;    
        }while (arr[i] < piv);
        do {
            j--;    
        }while (arr[j] > piv);
        
        if (i<j){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
        } 
        /*Que pasaria si estiviera aqui lo del piv*/
    }
    arr[low] = arr[j];
    arr[j] = piv;
    
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quickSort(arr, low, j-1);/*Excluir al pivote*/
        quickSort(arr, j + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    
}

void heapSort(int arr[], int n) {
    
}

void printArray(int arr[], int n) {
    if (n == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void SortingTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void SortingTimer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}

double SortingTimer::getElapsedMilliseconds() const {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count() / 1000.0;
}

std::string SortingTimer::getElapsedTime() const {
    double ms = getElapsedMilliseconds();
    std::stringstream ss;
    
    if (ms < 1.0) {
        ss << std::fixed << std::setprecision(3) << (ms * 1000) << " microseconds";
    } else if (ms < 1000.0) {
        ss << std::fixed << std::setprecision(3) << ms << " ms";
    } else {
        ss << std::fixed << std::setprecision(3) << (ms / 1000.0) << " seconds";
    }
    
    return ss.str();
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr = generateSortedArray(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    for (int i = 0; i < swaps && i < size/2; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

}