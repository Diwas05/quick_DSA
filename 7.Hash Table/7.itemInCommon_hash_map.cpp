#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool itemInCommon(vector<int> v1,vector<int> v2){
    unordered_map<int, bool> myMap;
    for(auto i:v1){
        myMap.insert({i,true});
    }

    for(auto j:v2){
        if(myMap[j]) return true;
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