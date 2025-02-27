// LINK: https://www.youtube.com/watch?v=1jCFUv-Xlqo&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=24

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i=1; i<n;i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr) {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}

int main() {
    int size = 5;
    int arr[] = {4, 1, 5, 2, 3};
    insertionSort(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
