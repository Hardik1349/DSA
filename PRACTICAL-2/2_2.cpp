#include<iostream>
using namespace std;

int main(){
    int arr[6] = {101, 201, 301, 401, 501, 601};
    int i=0,j=5,mid;
    int key=301;
    while(i<=j){
        mid=i+(j-i)/2;
        if(arr[mid]==key){
            cout << "Element found at index " << mid << endl;
            cout << "Element found " << arr[mid] << endl;
            return arr[mid];
        }
        else if(arr[mid]<key){
            i = mid + 1;
        }
        else if(arr[mid]>key){
            j = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    return -1;
}