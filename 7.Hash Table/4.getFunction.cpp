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
        int hash(string key){
            int hash = 0;\
            for(int i=0;i<key.length();i++){
                int asciiValue = int (key[i]);
                hash = (hash+asciiValue*23)%SIZE;
            }
            return hash;        
        }
        //Set function for insertion
        void set(string key, int value){
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if(dataMap[index] == NULL){
                dataMap[index] = newNode;
            }else{
                Node* temp = dataMap[index];
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        //Get function will return the value of the pair and if not present then will return 0.
        int get(string key){
            int index = hash(key);
            Node* temp = dataMap[index];
            while(temp!=NULL){
                if(temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }
};
int main(){
    HashTable* myHT = new HashTable();
    myHT->set("nails",100);
    myHT->set("tile",50);
    myHT->set("lumber",80);


    cout<<"Lumber: "<<myHT->get("lumber")<<endl;
    cout<<"bolts: "<<myHT->get("bolts")<<endl;


}