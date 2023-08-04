#include<iostream>
using namespace std;

int binary(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        if(key>arr[mid]){
            start = mid +1;
        }
        if(key < arr[mid]){
            end = mid -1;
        }
        mid = (start+end)/2;
    }
    return -1;
}
int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9};
    int size = 9;
    int key = 7;
    int result = binary(arr,size,key);
    if(result == -1){
        cout<<"The element is not present"<<endl;
    }else{
        cout<<"The element is present at index:"<<result<<endl;
    }
}