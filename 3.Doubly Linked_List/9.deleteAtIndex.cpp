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
        //CONSTRUCTOR
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        //Destructor
        ~DoublyLinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        void print(){
            Node* temp =head;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        //1.Append at tail
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
        //2.Delete last node
        void deleteLast(){
            Node* temp = tail;
            if(length==0){
                cout<<"Sorry the list is empty"<<endl; 
                return;
            }
            if(length==1){
                head = NULL;
                tail = NULL;
            }else{
                tail = tail->prev;
                tail->next = NULL;
                temp->prev = NULL;
            }
            delete temp;
            length--;
        }
        //3.Prepend at HEAD
        void prepend(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }
        //4.Delete FIRST NODE
        void deleteFirst(){
            Node* temp = head;
            if(length==0){
                return;
                cout<<"Sorry the list is Empty!!";
            }
            if(length==1){
                head = NULL;
                tail = NULL;
            }else{
                Node* temp = head;
                head = temp->next;
                temp->next = NULL;// this is optional

                head->prev = NULL;
            }
            delete temp;
            length--;
        }
        //5.get Function
        Node* get(int index){
            //checking for index out of range or not
            //NOTE:~ WE CAN ALSO USE Singly_LL get Function, BUT TO OPTIMISE WE HAVE DIVIDED INTO TWO HALF SECTIONS
            
            if(index<0 || index>=length){
                return nullptr;
            }
            Node* temp = head;
            if(index<length/2){
                for(int i=0;i<index;i++){
                    temp = temp->next;
                }
            }else{
                temp = tail;
                for(int i=length-1;i>index;i--){
                    temp = temp->prev;
                }
            }
            return temp;
        }
        // 6.set function
        bool set(int index, int value){
            Node* temp = get(index);
            if(temp){
                temp->value = value;
                return true;
            }
            return false;
        }
        // 7. Insert at index
        bool insert(int index,int value){
            if(index<0 || index>=length){
                return false;
            }
            if(index == 0){
                prepend(value);
                return true;
            }
            if(index == length){
                append(value);
            }
            Node* newNode = new Node(value);
            Node* before = get(index-1);
            Node* after = before->next;
            newNode->prev = before;
            newNode->next = after;
            before->next = newNode;
            after->prev = newNode;
            length++;
        }
        //8.Delete at ant index
        void deleteNode(int index){
            if(index<0 || index>=length) return;
            if(index==0) return deleteFirst();
            if(index==length-1) return deleteLast(); 
            Node* temp = get(index);

            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
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
    DoublyLinkedList* myDLL = new DoublyLinkedList(0);
    //  myDLL->print();

    myDLL->append(1);
    // myDLL->print();

    myDLL->append(2);
    // myDLL->print();

    myDLL->append(4);
    // myDLL->print();

    cout<<myDLL->get(1)->value<<endl;
    cout<<myDLL->get(2)->value<<endl;

    // changing index 3
    // myDLL->set(3,4);
    // myDLL->print();
    cout<<"List before insertion:"<<endl;
    myDLL->print();
    cout<<"List after Insertion:"<<endl;
    myDLL->insert(3,3);
    myDLL->print();
    myDLL->getLength();

    cout<<"List after Deletion:"<<endl;
    myDLL->deleteNode(3);
    myDLL->print();


}
