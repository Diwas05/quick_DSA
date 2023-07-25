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
        ~Stack(){
            Node* temp = top;
            while(top){
                top = top->next;
                delete temp;
                temp = top;
            }
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
            //NOTE:~ No need to write any extra conditions for empty stack because we don't have any bottom ponter here.
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }
        //3.pop Function
        int pop(){
            if(height == 0) return INT16_MIN;

            Node* temp = top;
            int poppedValue = top->value;
            top=top->next;
            delete temp;
            height--;

            return poppedValue;
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

    cout<<"Popped value: "<<myStack->pop()<<endl;

    cout<<"Popped value: "<<myStack->pop()<<endl;

}