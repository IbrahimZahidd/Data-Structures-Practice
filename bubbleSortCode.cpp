// LINK: https://www.youtube.com/watch?v=1jCFUv-Xlqo&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=24

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool isSwap=false;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) { // Compare adjacent elements
                swap(arr[j], arr[j+1]); // Swap if they are in the wrong order
                isSwap=true;
            }
        }
        if(isSwap == false) {
            return;
        }
    }
}

int main() {
    int size = 5;
    int arr[] = {4, 1, 5, 2, 3};
    bubbleSort(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
