 // Reference: Apna College C++ DSA playlist

#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    next = NULL;
  }
    
};

class List {
  Node* head;
  Node* tail;
public:
 List() {
    head = tail = NULL;
 }
 
 void push_front(int val) {
    Node* newNode = new Node(val);
    if(head != NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        head = tail = newNode;
        return;
    }
 }
 
 void print_LL() {
    Node* temp = head;
    cout<<"The linked list is: ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
 }
 
 void push_back(int val) 
 {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head  = tail = newNode;
        return;
    } else {
        //if no tail is given
        /* 
        Logic: 
        
        1) create a temp variable, set it to head. 
        2) Traverse ll till "temp->next == NULL". 
        3) This is the last Node. Here insert the newNode."temp->next = newNode"
        */
    
        // tail is given
        tail->next = newNode;
        tail = newNode;
    }
 }
 
 void pop_front() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
 }
 
 void pop_back() {
    if (head == NULL) {
        return;
    }
    Node *temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
    
 }
 
 void insertAtAnyIndex(int val, int pos) {
    if(head == NULL || pos < 0) {
        return;
    }
    if (pos == 0) {
        push_front(val);
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for(int i=0; i<pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next =  newNode;
 }
 
 int search(int key) {
    Node* temp = head;
    int idx=0;
    while (temp->data != key) {
        temp = temp->next;
        if(temp == NULL) {
            return -1;
        }
        idx = idx + 1;
    }
    return idx;
 }
};

int main()
{
    List ll; //linked List
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_LL();
    ll.push_back(40);
    ll.print_LL();
    ll.push_front(50);
    ll.print_LL();
    ll.pop_front();
    ll.print_LL();
    ll.pop_back();
    ll.print_LL();
    ll.insertAtAnyIndex(60,3);
    ll.print_LL();
    cout<<"The search result is: "<<ll.search(30)<<endl;
    cout<<"The search result is: "<<ll.search(20)<<endl;
    cout<<"The search result is: "<<ll.search(10)<<endl;
    cout<<"The search result is: "<<ll.search(60)<<endl;
    cout<<"The search result is: "<<ll.search(-1)<<endl;
    return 0;
}
