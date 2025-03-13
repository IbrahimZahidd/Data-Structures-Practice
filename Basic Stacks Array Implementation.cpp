#include <iostream>
#include <vector>
using namespace std;

class Stack {
    int top, cap;
    int *a;

public:
    Stack(int cap) {
        this->cap = cap;
        top=-1;
        a=new int[cap];
    }
    
    ~Stack() {
        delete[] a;
    }
    
    bool push(int x) {
        if(top==cap-1) {
            cout<<"Stack Overflow\n";
            return false;
        }
        a[++top]=x;
        return true;
    }
    
    int pop() {
        if (top<0) {
            cout<<"Stack is Empty\n";
            return 0;
        }
        return a[top--];
    }
    
    int peek() {
        if(top<0) {
            cout<<"Stack is Empty\n";
            return 0;
        }
        return a[top];
    }
    
    bool isEmpty() {
        return top<0;
    }
};

int main()
{
    Stack s(5);
    for(int i=0;i<5;i++) {
        s.push(i);
    }
    cout<<"Performing popping: "<< s.pop() << " popped from stack.\n";
    cout<<"Top element is: "<<s.peek()<<endl;
    cout<< "All Elements in Stack: ";
    while(!s.isEmpty()) {
        cout<<s.peek() <<" ";
        s.pop();
    }
    
    return 0;
}
