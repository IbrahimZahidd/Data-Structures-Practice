#include <iostream>
#include <vector>
using namespace std;

bool binarySearchIterative(vector<int>& arr, int size, int target) {
    int start = 0, end = size-1, mid=0;
    while(start<=end) {
        mid = start + ((end - start)/2);
        if(arr[mid]<target) {
            start = mid+1;
        } else if (arr[mid]>target) {
            end = mid -1;
        } else {
            return true;
        }
    }
    return false;
}

bool binarySearchRecursive(vector<int>& arr, int start, int end, int target) {
    if (start > end) {
        return false;  // Base case: the target is not found
    }
    int mid = start + ((end - start)/2);
    if (arr[mid]>target) {
        return binarySearchRecursive(arr, start,mid-1, target);
    } else if (arr[mid]<target) {
        return binarySearchRecursive(arr, mid+1, end, target);
    } else {
        return true;
    }
}

int main()
{
    // vector<int> arr = {1, 5, 15, 21, 39, 54};
    // vector<int> arr = {1, 5, 15, 15, 15, 39, 54};
    // vector<int> arr = {15};
    // vector<int> arr = {-10, -5, 0, 5, 10, 15, 20};
    // vector<int> arr = {-10, -5, -2, -1};
    int target = 7;
    // int target = 15;
    int size = arr.size();
    int start = 0, end=size-1;
    // cout<<"The answer for iterative is: "<<binarySearchIterative(arr, size, target);
    cout<<"The answer for recursive is: "<<binarySearchRecursive(arr, start, end, target);
    return 0;
}
