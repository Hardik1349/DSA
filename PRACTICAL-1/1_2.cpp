#include<iostream>
using namespace std;

int main(){
    int arr[5] = {101, 201, 101, 401, 401};
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]==arr[j]){
                cout << arr[j] << " ";
            }
        }
    }
    return 0;
}