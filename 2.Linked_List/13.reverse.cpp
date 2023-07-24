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
        void deleteLast(){
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
        //6.getFunction to get the index of the node(position)
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
        //7.Set Function: returns true if it was able to set the values, otherwise returns false
        //Set Function is used to change the value in the present index
        bool set(int index, int val){
            Node* temp = get(index);//Checking for the index, whether it is inside the range or outside the range.
            if(temp){//meaning if temp is pointing to any of the node, then this condition will be applicable.
            temp->value = val;
            return true;
            }
            return false;
        }

        //8.Insert at index
        bool insert(int index, int value){
            //checking the index whether it out of range or not
            if(index<0||index>length){
                return false;
            }
            if(index==0){
                prepend(value);
                return true;
            }
            if(index == length){
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index-1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;

        }
        
        //9.Delete at index
        void deleteNode(int index){
            if(index<0||index>length) return;
            if(index==0) return deleteFirst();
            if(index==length-1) return deleteLast();

            Node* prev = get(index-1);
            Node* temp = prev->next;

            prev->next=temp->next;
            delete temp;
            length --;
        }
        //10.Reverse the linked list
        void reverse(){
            Node* temp = head;
            //Swapping head and tail using temp pointer
            head = tail;
            tail = temp;
            //Creating two more pointer, "before" pointing to the null and "after" pointing to temp->next
            Node* after = temp->next;
            Node* before = NULL;
            //Now using for loop we are reversing the pointer
            for(int i=0;i<length;i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            } 
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
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    cout<<"Original linked list: "<<endl;
    myLinkedList->print();
    cout<<"Reversed linked list: "<<endl;
    myLinkedList->reverse();
    myLinkedList->print();



}