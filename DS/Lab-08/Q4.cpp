#include <iostream>
#include <vector>
using namespace std;

class Node{
    string data;
    Node *right;
    Node *left;

    public:
    Node(string data) : data(data), right(nullptr), left(nullptr) {}
    friend class BST;
};

class BST{

    Node *insertion(Node *head, string data){
        if(head == nullptr) return new Node(data);
        if(head->data == data) return head;
        if(data < head->data) head->left = insertion(head->left, data);
        else head->right = insertion(head->right, data);
        return head;
    }

    void perorder(Node *root){
        if(root == nullptr){
            cout << "-1" << " ";
            return;
        }
        cout << root->data << " ";
        perorder(root->left);
        perorder(root->right);
    }

    bool isExist(Node* root, string data){
        if(root == nullptr) return false;
        if(root->data == data) return true;
        return data < root->data ? isExist(root->left, data) : isExist(root->right, data);
    }

    public:

    Node *head;
    BST() : head(nullptr) {}

    void insert(string data){
        head = insertion(head, data);
    }

    void traverse(){
        perorder(head);
    }

    void subTree(Node *a, Node *b){
        if(b == nullptr) return;
        if(isExist(a, b->data)){
            head = insertion(head, b->data);
        }    
        subTree(a, b->left);
        subTree(a, b->right);
    }
};

int main(){
    BST t1;
    t1.insert("1");
    t1.insert("3");
    t1.insert("8");
    t1.insert("2");
    t1.insert("5");
    t1.insert("6");
    t1.traverse();

    BST t2;
    t2.insert("3");
    t2.insert("8");
    t2.insert("2");

    BST t3;
    t3.subTree(t1.head,t2.head);
    cout<<"\nTraversal Of Sub Tree: ";
    t3.traverse();;
}
