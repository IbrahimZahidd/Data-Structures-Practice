#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

int main()
{
    //basic concepts
    // int bb = 5;
    // int* aa = &bb;
    // int* cc = aa;
    // cout<< *aa<<" " <<*cc<<endl;
    // cout<< aa<<" " <<cc<<endl;
    
    //first is a pointer of type Node and it contains the address of newly created Node on heap.
    Node* first = new Node(2); 
    
    // concept clarification
    // int* a = new int(4);
    // cout <<"Address of 2: "<<a<<endl;
    // cout<<"Address of node: "<<first<<endl;
    
    //next is a pointer of type Node and it contains the address of newly created Node on heap.
    first->next = new Node(3); 
    
    /*
    last is a pointer of type Node
    first->next->next is also a pointer of type Node.
    Therefore, both starts pointing to the same Node now.
    */
    first->next->next = new Node(4);
    Node *last = first->next->next;
    // cout<<last<<" "<<first->next->next<<endl;
    
        /*
    last is a pointer of type Node
    first is a pointer of type Node too
    Therefore, both starts pointing to the same Node now.
    */
    last->next = first;
    
}
