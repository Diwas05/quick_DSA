#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};
class BST{
    public:
        //root will point to the top parent node initially
        Node* root;

    public:
            //Instead of creating the node, we can assume that the root node is empty at the time of creation.
            //So, we don't need to pass a value in BST().
        BST(){
        //     Node* newNode = new Node(value);
        //     root = newNode;
        root = nullptr;
        }
};

int main(){
    BST* myBST = new BST();
    cout<<"Root: "<<myBST->root<<endl;
} 