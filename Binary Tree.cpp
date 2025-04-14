/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int data) {
        this->data = data;
    }
    
};

static int idx = -1;
Node* buildTree(vector<int> preOrder) {
        idx++;
        if(preOrder[idx]==-1) 
        {
            return NULL;
            
        }
        Node* root = new Node(preOrder[idx]);
        root->leftChild = buildTree(preOrder);
        root->rightChild = buildTree(preOrder);
        return root;
    }

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);
}


void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->leftChild);
    cout<<root->data<<" ";
    inOrderTraversal(root->rightChild);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(q.size()>0) {
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->leftChild != NULL) {
            q.push(curr->leftChild);
        }
        if(curr->rightChild != NULL) {
            q.push(curr->rightChild);
        }
    }
}

void levelOrderTraversal2(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0) {
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {
            if(!q.empty()) {
                cout<<endl;
                q.push(NULL);
                /*we dont check left and right childs for NULL node.
                Therefore, we skipped to next iteration.*/
                continue; 
            } else {
                break;
            }
        }
        
        cout<<curr->data<<" ";
        if(curr->leftChild != NULL) {
            q.push(curr->leftChild);
        }
        if(curr->rightChild != NULL) {
            q.push(curr->rightChild);
        }
    }
}

int main()
{
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    Node* root = buildTree(preOrder);
    
    // cout<<root->data<<endl;
    // cout<<root->leftChild->data<<endl;
    // cout<<root->rightChild->data<<endl
    
    // preOrderTraversal(root);
    
    // inOrderTraversal(root);
    
    // postOrderTraversal(root);
    
    // levelOrderTraversal(root);
    
    levelOrderTraversal2(root);
    
    cout<<endl;
    return 0;
}
