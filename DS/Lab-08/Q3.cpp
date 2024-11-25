#include <iostream>
#include <algorithm>

using namespace std;
class Node{
    
    public:

    int data; 
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {

    Node* root;

    int maxProfitPath(Node* node) {
        if(node == nullptr) return 0;
        int Left = maxProfitPath(node->left);
        int Right = maxProfitPath(node->right);
        return node->data + std::max(Left, Right);
    }

    public:

    BinaryTree() : root(nullptr) {}

    void setRoot(Node* node) { root = node; }
    int getMaxProfitPath() { return maxProfitPath(root); }

    ~BinaryTree() {
        deleteTree(root);
    }

    void deleteTree(Node* node){
        if(node){
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }
};

int main() {
    
    BinaryTree tree;
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(11);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    tree.setRoot(root);

    int maxProfit = tree.getMaxProfitPath();
    cout << "Maximum profit path: " << maxProfit << endl;
}
