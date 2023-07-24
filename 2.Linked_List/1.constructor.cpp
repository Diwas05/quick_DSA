#include <iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    // Constructor
    Node(int data){
        this->value = data;
        this->next = NULL;
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
       
};
int main(){
    LinkedList* myLinkedList = new LinkedList(4);

}
