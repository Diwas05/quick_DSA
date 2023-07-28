#include <iostream>
#include <vector>
using namespace std;

bool itemInCommon(vector<int> v1,vector<int> v2){
    for(auto i:v1){
        for(auto j:v2){
            if(i==j) return true;
        }
    }
    return false;
}

int main(){
    vector<int> v1 {1,3,5};
    vector<int> v2 {2,4,5};
    vector<int> v3 {2,4,6};
    cout<<itemInCommon(v1,v2)<<endl;
    cout<<itemInCommon(v1,v3)<<endl;
}