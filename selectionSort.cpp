// LINK: https://www.youtube.com/watch?v=1jCFUv-Xlqo&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=24

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1;i++) {
        int smallestIndex=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[smallestIndex]) {
                smallestIndex=j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}

int main() {
    int size = 5;
    int arr[] = {4, 1, 5, 2, 3};
    selectionSort(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
