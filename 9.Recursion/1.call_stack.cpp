#include<iostream>
using namespace std;

void funThree(){
    cout<<"Three"<<endl;
}
void funTwo(){
    funThree();
    cout<<"Two"<<endl;
}
void funOne(){
    funTwo();
    cout<<"One"<<endl;
}

int main(){
    funOne();
    return 0;
}