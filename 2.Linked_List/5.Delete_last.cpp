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
        //printing the list
        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        //Appending the node at tail
        void append(int value){
            Node* newNode = new Node(value);            
            //Checking for empty linked list
            if(length==0){
                head = newNode;
                tail = newNode;
            }else{
                //tail is pointing to newNode
                tail->next = newNode;
                //Shifting tail to newNode
                tail = newNode;
            }
            length++;
        }
        //Deleting the last node
        void deleteNode(int value){
            //For empty list
            if(length==0){
                return;
            }
            Node* temp=head;
            Node* pre = head;
            while(temp->next!=NULL){
                pre = temp;
                temp=temp->next;
            }
            tail = pre;
            tail->next = NULL;
            delete temp;
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
    
    myLinkedList->append(6);
    myLinkedList->print();

    myLinkedList->append(8);
    myLinkedList->print();

    myLinkedList->deleteNode(8);
    myLinkedList->print();
    
    

}