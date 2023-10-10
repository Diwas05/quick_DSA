//creating a cookie class
#include <iostream>
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
    Cookie* newCookie = new Cookie("Blue");
    Cookie* CookieTwo = new Cookie("Green");
    newCookie->setColor("Yellow");
    cout<<"C1:"<<newCookie->getColor()<<endl;
    cout<<"C2:"<<CookieTwo->getColor()<<endl;
}