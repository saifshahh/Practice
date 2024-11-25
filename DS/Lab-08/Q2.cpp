#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            data = data;
            left = nullptr;
            right = nullptr;
        }
};

vector<int> zigzagOrder(Node* root) {
    
    vector<int> result;

    if(root == nullptr) return result;

    stack<Node*> curr;
    stack<Node*> next;

    curr.push(root);
  
    bool LR = true;
    while(!curr.empty()){
        
        int size = curr.size();
        
        while(size--){

            struct Node* current = curr.top();
            curr.pop();
            result.push_back(current->data);
         
            if(LR){
                if(current->left) next.push(current->left);
                if(current->right) next.push(current->right);
            }
            else{
                if(current->right) next.push(current->right);
                if(current->left) next.push(current->left);
            }
        }
        LR = !LR;
        swap(curr, next);
    }
    return result;
}

void printList(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    vector<int> result = zigzagOrder(root);
    printList(result);
}
