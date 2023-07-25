#include <iostream>
using namespace std;
class Node{
    public:
        int value;
        Node* next;

        //CONSTRUCTOR
        Node(int value){
            this->value = value;
            this->next = NULL;
        }
};
class Queue{
    private:
        Node* first;
        Node* last;
        int length;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;

        }
        void print(){
            Node* temp = first;
            while(temp){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        //Enqueue->Adding element
        void enqueue(int value){
            Node* newNode = new Node(value);
            if(length==0){
                first = newNode;
                last = newNode;
            }else{
                last->next = newNode;
                last = newNode;
            }
            length++;

        }
        //Dequeue->Removing element
        int dequeue(){
            if(length==0) return INT16_MIN;
            Node* temp = first;
            int dequeueValue = first->value;
            if(length==1){
                first = NULL;
                last = NULL;
            }else{
                first = first->next;
            }
            delete temp;
            length--;
            return dequeueValue;

        }
        void getFirst(){
            cout<<"First: "<<first->value<<endl;
        }
        void getLast(){
            cout<<"Last: "<<last->value<<endl;
        }
        void getLength(){
            cout<<"Length: "<<length<<endl;
        }

};
int main(){
    Queue* myQueue = new Queue(2);
    
    myQueue->enqueue(1);

    cout<< "Dequeued value: "<< myQueue->dequeue()<<endl;

    cout<< "Dequeued value: "<< myQueue->dequeue()<<endl;

    cout<< "Dequeued value: "<< myQueue->dequeue()<<endl;

    // myQueue->print();
}


