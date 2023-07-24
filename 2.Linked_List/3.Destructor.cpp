#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    //Constructor
    Node(int val){
        this->value=val;
        this->next=NULL;
    }
};
class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        //Constructor
        LinkedList(int val){
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        //Destructor
        ~LinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
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
    LinkedList* myLinkedList = new LinkedList(4);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->print();
    delete myLinkedList;
    myLinkedList->print();

}
