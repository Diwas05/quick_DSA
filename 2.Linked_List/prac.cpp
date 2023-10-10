#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value=value;
            next=nullptr;
        }
};
class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        ~LinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        void append(int value){
            Node* newNode = new Node(value);
            if(length==0){
                head = newNode;
                tail = newNode;
            }
            tail->next = newNode;
            tail = newNode;
            length++;
        }
        void printList(){
            Node* temp = head;
            while(temp){
                cout << temp->value << " ";
                temp=temp->next;
            }
            cout<<endl;
        }
        void getHead(){
            cout<<"Head:"<<head->value<<endl;
        }
        void getTail(){
            cout<<"Tail:"<<tail->value<<endl;
        }
        void getLength(){
            cout<<"Length:"<<length<<endl;
        }
};
int main(){
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();
    myLinkedList->append(23);
    myLinkedList->append(34);
    myLinkedList->printList();
}