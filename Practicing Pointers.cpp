#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // concept 0
    
    int* ptr0;
    int data0=1;
    ptr0=&data0;
    cout<<"Concept 0: "<<*ptr0<<" "<<"ptr0_value("<<ptr0<<")"<<" "<<&ptr0<<endl;
    
    // concept 1
    
    int* ptr1;
    int data1=1;
    ptr1=&data1;
    cout<<"Concept 1: "<<*ptr1<<endl;
    
    // concept 2
    
    int* ptr2;
    int* ptr3;
    int data2=1;
    ptr2=&data2;
    ptr3=ptr2;
    cout<<"Concept 2: "<<*ptr2<<" "<<*ptr3<<endl;
    
    // concept 3
    
    int *ptr4 = new int[4];
    for(int i=0;i<4;i++) {
        *(ptr4 + i) = i;
    }
    cout<<"Concept 3: ";
    for(int i=0;i<4;i++) {
        cout<<*(ptr4+i)<<" ";
    }
    cout<<endl;
    
    // concept 4

    int ** dPtr1;
    int *ptr5;
    int data3=1;
    ptr5 = &data3; 
    dPtr1 = &ptr5;
    cout<<"Concept 4: "<<*ptr5<<" "<<**dPtr1<<endl;
    
    // concept 5

    int ** dPtr2;
    int *ptr6;
    int data4=1;
    ptr6 = &data4; 
    dPtr2 = &ptr6;
    cout<<"Concept 5: "<<&ptr5<<" "<<dPtr1<<endl;
    
    // concept 6
    int* ptr7 = nullptr; // Use nullptr to initialize pointers
    if (ptr7 == nullptr) {
        cout << "Concept 6: "<< "Pointer is null" << endl;
    }
    
    // concept 7: Static vs Dynamic Array

    // Static Array
    int staticArray[4] = {10, 20, 30, 40}; // Static array with 4 elements
    cout << "Concept 7: Static Array: ";
    for (int i = 0; i < 4; i++) {
        cout << staticArray[i] << " ";
    }
    cout << endl;
    // Dynamic Array
    /* Dynamically allocate an array of 4 elements. 
    We can enter the size at runtime aswell but,
    we cant do that for static arrays*/
    int* dynamicArray = new int[4];     for (int i = 0; i < 4; i++) {
        dynamicArray[i] = (i + 1) * 10; // Assign values to dynamic array
    }
    cout << "Dynamic Array: ";
    for (int i = 0; i < 4; i++) {
        cout << dynamicArray[i] << " ";
    }
    
    
    cout << endl;
    
    // concept 8
    
    void* ptr8; // can point to any datatype
    int data5=1;
    ptr8=&data5;
    cout<<"Concept 8: "<< *(static_cast<int*>(ptr8)) <<endl; // Telling compiler the data type
    
    // Add any more concepts as you keep on learning
    
    
    // Deallocate memory for dynamic array
    delete[] dynamicArray;

    // concept 9

    int a=1;
    int* b=&a;
    int* c;
    c=b;
    cout<<*c;

    // concept 10

    int a = 5;
    int *b = &a;
    int **c = &b;
    cout<< &a << " " << b << " " << *b<<endl;
    cout<< &b << " " << " " << c << " " << **c << " " << &c << " " << *c << endl;
    
    return 0;
}

/*

**c = *(*c) = *(b) = *b = 5

*/
