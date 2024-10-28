#include <iostream>
#include<vector>
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
    Node *head;
    Node* insertion(Node *head, string data){
        if(head == nullptr) return new Node(data);
        if(head->data == data) return head;  
        if(data < head->data) head->left = insertion(head->left, data);  
        else head->right = insertion(head->right, data);
        return head;
    }

public:
    BST() : head(nullptr) {}

    void insert(string data){ head = insertion(head, data); }

    void preOrderTraversal(Node *root){
        if(root == nullptr){
            cout<<"-1"<<" ";
            return;
        }
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    void traverse(){ preOrderTraversal(head); }

    void transfer(Node* root, vector<string>& s){
        if(root == nullptr) return;
        s.push_back(root->data);
        transfer(root->left, s);
        transfer(root->right, s);
    }

    BST catchtree(){
        vector<string> s;
        transfer(head, s);
        BST t2;
        for(int i=0; i<s.size(); i++){
            t2.insert(s[i]);
        }
        return t2;
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

    BST t2 = t1.catchtree();
    cout << "\nNew BST (pre-order): ";
    t2.traverse();
    cout << endl;
}
