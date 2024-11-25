#include <iostream>
using namespace std;

class Node{

    public:

    int data;
    Node *left;
    Node *right;

    Node(int d) : data(d){
        left = nullptr;
        right = nullptr;
    }
    friend class BST;
};

class BST{

    Node *head;
    Node *insertion(Node *head, int data){
        if(head == nullptr) return new Node(data);
        if(head->data == data) return head;
        if(data < head->data) head->left = insertion(head->left, data);
        else head->right = insertion(head->right, data);
        return head;
    }

public:
    BST() : head(nullptr) {}
    BST(Node *n) : head(n) {}

    void insert(int data){
        head = insertion(head, data);
    }

    Node* getHead(){
        return head;
    }
};

Node* swap(Node* root, int& value1, int& value2){
    if(root == nullptr) return nullptr;

    if(root->data == value1) root->data = value2;
    else if (root->data == value2) root->data = value1;
    
    swap(root->left, value1, value2);
    swap(root->right, value1, value2);

    return root;
}

void InOrderTraversal(Node *root){
    if (root == nullptr) return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

int main(){
    BST t1;
    t1.insert(10);
    t1.insert(5);
    t1.insert(15);
    t1.insert(3);
    t1.insert(7);
    t1.insert(12);
    t1.insert(18);

    cout << "In-order before swapping: ";
    InOrderTraversal(t1.getHead());
    cout << endl;

    int value1 = 7, value2 = 15;
    swap(t1.getHead(), value1, value2);

    cout << "In-order after swapping: ";
    InOrderTraversal(t1.getHead());
    cout << endl;
}
