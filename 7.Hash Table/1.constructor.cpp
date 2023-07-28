#include <iostream>
using namespace std;
class Node{
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value){
            this->key = key;
            this->value = value;
            next = NULL;        
            }
};

class HashTable{
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        void print(){
            for(int i=0;i<SIZE;i++){
                cout<<i<<":"<<endl;
                if(dataMap[i]){
                    Node* temp = dataMap[i];
                    while(temp){
                        cout<<"   {"<<temp->key<<", "<<temp->value<<"}"<<endl;
                        temp = temp->next;
                    }
                }
            }
        }
};
int main(){
    HashTable* myHT = new HashTable();
    myHT->print();
}