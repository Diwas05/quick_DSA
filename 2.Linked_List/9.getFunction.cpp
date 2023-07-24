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
        //1.printing the list
        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        //2.Appending the node at tail
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
        //3.Prepending at head node
        void prepend(int value){
            Node* newNode = new Node(value);\
            //Empty list
            if(length==0){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode;
            }
            length++;
        }
        //4.Deleting the last node
        void deleteLast(int value){
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
            length--;
            //Here 1 node delettion is an edge case, therefore we need to adderss it separately.
            
            //Meaning after deleting the single node we need to make both head and tail NULL. 
            if(length==0){
                head = NULL;
                tail = NULL;
            } 
            delete temp;
        }
        //5.Deleting from FIRST
        void deleteFirst(){
            //Empty list
            Node* temp = head;
            if(length == 0){
                return;
            }
            //Only one Node is present
            if(length==1){
                head=NULL;
                tail=NULL;
            }else{
                head = head->next;
            }
            delete temp;
            length--;

        }
        //getFunction to get the index of the node(position)
        Node* get(int index){
            if(index < 0 || index >= length){
                return NULL;
            }
            Node* temp = head;
            for(int i=0;i<index;i++){
                temp = temp->next;
            }
            return temp;
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
    LinkedList* myLinkedList = new LinkedList(2);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    
    myLinkedList->print();
    
    myLinkedList->append(3);
    myLinkedList->print();

    myLinkedList->append(4);
    myLinkedList->print();

    cout<<myLinkedList->get(2)<<endl;
    cout<<myLinkedList->get(2)->value<<endl;
}