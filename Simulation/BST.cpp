#include <iostream>
using namespace std;

class BST{

    private:

    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int data=0) : data(data), left(nullptr), right(nullptr) {}
    };

    int height(Node* root){
        if(root==nullptr) return -1;
        else{
            int lheight = height(root->left);
            int rheight = height(root->right);
            return (lheight > rheight) ? lheight+1 : rheight+1;
        }
    }

    void printLevel(Node* root, int level){
        if(root==nullptr) return;
        else if(level == 0) cout<<root->data<<" ";
        else{
            printLevel(root->left, level-1);
            printLevel(root->right, level-1);
        }
    }

    void levelOrder_BFS(Node* root){
        int h = height(root);
        for(int i=0; i<=h; i++){
            printLevel(root, i);
        }
    }

    Node* minNode(Node* node){
        while(node && node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* root, int value){
        if(root == nullptr) return root;
        if(root->data < value) root->right = deleteNode(root->right, value);
        else if(root->data > value) root->left = deleteNode(root->left, value);
        else{
            if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node* temp = minNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data); 
            }
        }
        return root;
    }

    public:
    
    Node *root;
    BST(): root(nullptr) {}

    void insert(int value){
        Node* newNode = new Node(value);

        if(root==nullptr){
            root = newNode;
            return;
        }

        Node* temp = root;

        while(temp != NULL){
            if(newNode->data == temp->data) return;
            else if(newNode->data < temp->data && temp->left == NULL){
                temp->left = newNode;
                break;
            }
            else if(newNode->data < temp->data) temp = temp->left;
            else if(newNode->data > temp->data && temp->right == NULL){
                temp->right = newNode;
                break;
            }
            else temp = temp->right;
        }
    }

    void search(int value){ 
        Node* temp = root;

        while(temp){
            if(temp->data == value){
                cout<<"\nNode found: "<<temp->data<<endl;
                break;
            }
            else if(value>temp->data) temp = temp->right;
            else temp = temp->left;
        }
    }

    void deleteNode(int key){
        Node* toDelete = deleteNode(root, key);
        if(toDelete) cout<<"Node Deleted!"<<endl;
        else cout<<"Such node doesnt exsist in the tree!"<<endl;
    }

    void BFS(){
        cout<<"BFS: "<<endl;
        levelOrder_BFS(root);
    }
};

int main(){
    BST tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);

    tree.BFS();
    tree.search(3);

    tree.deleteNode(3);
    tree.BFS();
}
