#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        //constructor
        Node(int value){
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};
class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        void print(){
            Node* temp =head;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        //Append at tail
        void append(int value){
            Node* newNode = new Node(value);
            //For empty list
            if(length==0){
                head = newNode;
                tail = newNode;
            }else{
                 tail->next = newNode;
                 newNode->prev = tail;
                 tail = newNode;
            }
            length++;
        }
        void getHead(){
            cout<<"Head: "<<head->value<<endl;
        }
        void getTail(){
            cout<<"Tail: "<<tail->value<<endl;
        }
        void getLength(){
            cout<<"Length: "<<length<<endl;
        }
    
};
int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->print();

    myDLL->append(2);
    myDLL->print();

}
