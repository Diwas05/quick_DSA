#include<iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
        //constructor
        Node(int val){
            this->value = val;
            this->next = NULL;
        }
};

class Stack{
    private:
        Node* top;
        // Node* bottom is useless
        int height;
    
    public:
        //constructor
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        //1.print Function
        void print(){
            Node* temp = top;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        //2.push Function
        void push(int value){
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }
        void getTop(){
            cout<<"TOP: "<<top->value<<endl;
        }
        void getHeight(){
            cout<<"HEIGHT: "<<height<<endl;
        }
};

int main(){
    Stack* myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();
    myStack->print();

    myStack->push(5);
    myStack->print();
}