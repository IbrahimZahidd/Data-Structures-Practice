#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
        this->data=data;
        this->next=nullptr;
    }
};

class Stack {
    Node* head;
public:
    
    Stack() {
        this->head= nullptr;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    void push(int new_data) {
        
        // On in built stack, very bad
        // Node new_node(new_data);
        
        // On in built heap, ideal
        Node* new_node = new Node(new_data);
        if(!new_node) {
            cout<<"Stack Overflow\n";
        }
        new_node->next = head;
        head=new_node;
    }
    
    void pop() {
        if(this->isEmpty()) {
            cout<<"Stack underflow\n";
            
        } 
        else {
            Node* temp = head;
            head=head->next;
            delete temp;
        }
    }
    
    int peek() {
        if(!isEmpty()) {
            return head->data;
        } else {
            cout<<"Stack is empty\n";
            return 0;
        }
    }
};

int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    
    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // removing two elemements from the top
    cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    return 0;
}
