#include <bits/stdc++.h>
#include "maxheap.hpp"
using namespace std;

int parent(int* arr, int n, int i){
    if (i==1) return 0;
    return i/2;
}

int Left(int* arr, int n, int i){
    if (i*2 <= n) return i*2;
    return 0;
}

int Right(int* arr, int n, int i){
    if (i*2 + 1 <= n) return i*2 + 1;
    return 0;
}

void maxHeapify(int* arr, int n, int i){
    int Largest = i;
    int nodeLeft = Left(arr,n,i);
    int nodeRight = Right(arr,n,i);

    if (nodeLeft && arr[nodeLeft] > arr[Largest]) Largest = nodeLeft;
    if (nodeRight && arr[nodeRight] > arr[Largest]) Largest = nodeRight;

    if (Largest != i){
        swap(arr[i],arr[Largest]);
        maxHeapify(arr,n,Largest);
    }
}

void buildMaxHeap(int* arr, int n){
    for(int i=n/2; i>=1; i--) maxHeapify(arr,n,i);
}

void heapSort(int* arr, int n){
    buildMaxHeap(arr,n);
    for(int i=n; i>=1; i--){
        swap(arr[1],arr[i]);
        maxHeapify(arr,i-1,1);
    }
}
