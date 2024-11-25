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
};

Node* NewBST(int arr[], int start, int end){
    if(start > end) return nullptr;
    
    int mid = start + (end - start) / 2;
    Node *tree = new Node(arr[mid]);

    tree->left = NewBST(arr, start, mid - 1);
    tree->right = NewBST(arr, mid + 1, end);
    return tree;
}

void InOrderTraversal(Node *root){
    if(root == nullptr) return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    Node *root = NewBST(arr, 0, 6);
    InOrderTraversal(root);
}
