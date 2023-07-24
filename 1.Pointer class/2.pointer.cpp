#include<iostream>
using namespace std;
int main(){
    //creating the pointer n1 and assigning the value to it
    int* n1 = new int (11);
    int* n2 = n1;

    *n1 = 22;
    
    cout<<"n1 address="<<n1<<endl;
    cout<<"n2 address="<<n2<<endl;
    cout<<"n1 value="<<*n1<<endl;
    cout<<"n2 value="<<*n2<<endl;
}