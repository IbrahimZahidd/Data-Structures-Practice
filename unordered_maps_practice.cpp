/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[5];
    // key-value pairs
    unordered_map<string, int> m;
    m["Ibrahim"] = 100;
    m["Zainab"] = 200;
    m["Hassan"] = 300;
    m["Fatima"] = 400;
    m.insert({"Amna",500});
    
    //printing entire map
    for (const auto& pair: m) {
        cout<< pair.first << " roll no. is: "<< pair.second<<endl;
    }
    
    // check if key exits
    if (m.find("Jimmy") == m.end()) {
        cout<< "A key named Jimmy doesn't exist in the map named m." << endl;
    }
    
    // accessing values of each key
    int count = 0;
    for(const auto& pair: m) {
        arr[count] = pair.second;
        count++;
    }
    
    cout<<"The list of values of each key is: ";
    for (int i = 0 ; i < 5 ; i++) {
        cout<<arr[i] << " ";
    }
    cout<<endl;
    
    
    
    
}
