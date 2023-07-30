#include <iostream>
#include "maxheap.hpp"

using namespace std;

int main()
{
    int* arr = nullptr;
    int n;
    cout << "Input length of the array: "; cin >> n;
    arr = new int[n+2];
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    heapSort(arr,n);
    for(int i=1; i<=n; i++) cout << arr[i] << ' ';
    return 0;
}
