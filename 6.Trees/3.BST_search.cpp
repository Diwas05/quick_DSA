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
        BST(){
        root = nullptr;
        }
        //Insertion
        bool insert(int value){ 
            Node* newNode = new Node(value);
            if(root == NULL){
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true){
                if(newNode->value == temp->value) return false;
                if(newNode->value < temp->value){
                    if(temp->left == NULL){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == NULL){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }

        }
        //Search function
        bool search(int value){
            // No need of this if condition for empty tree bcz it is handeled by while loop itself
            // if(root == NULL){
            //     return false;
            // }
            Node* temp = root;
            while(temp!=NULL){
                if(value < temp->value){
                    temp = temp->left;
                }else if(value > temp->value){
                    temp = temp->right;
                }else{
                    return true;
                }
            }
            return false;
        }
};

int main(){
    BST* myBST = new BST();
    
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);

    myBST->insert(27);
    //Address of the node
    cout<<myBST->root->left->right<<endl;
    //Value of the node
    cout<<myBST->root->left->right->value<<endl;

    cout<<"Contains 27: " << myBST->search(27)<<endl;
    cout<<"Contains 17: " << myBST->search(17)<<endl;
} 