#include<iostream>
using namespace std;
class Cookie{
    private:
    string color;

    public:
    Cookie(string color){
        this->color = color;    
    }
    string getColor(){
        return color;
    }
    void setColor(string color){
        this->color = color;
    }
};
int main(){
    Cookie* cookieOne = new Cookie("green");
    Cookie* cookieTwo = new Cookie("blue");

    //Changing the color of cookieOne to yellow
    cookieOne->setColor("Yellow");

    //Printing the cookieOne and cookieTwo color
    cout<<"C1: "<<cookieOne->getColor()<<endl;
    cout<<"C2: "<<cookieTwo->getColor()<<endl;
}