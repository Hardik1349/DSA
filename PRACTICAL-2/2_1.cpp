#include<iostream>
#include<string>
using namespace std;

int findNumPlate(string arr[], int n, int size,string target){
    
    if(n >= size){
        return -1;
    }
    if(arr[n] == target){
        return n;
    }
    return findNumPlate(arr, n+1, size, target);
}

int main(){
    string arr[5]= {"GJ01-AB1234", "GJ02-CD5678", "GJ03-EF9012", "GJ04-GH3456", "GJ05-IJ7890"};     
    string target="GJ04-GH3456";
    int result = findNumPlate(arr, 0, 5, target);
    cout << "Number plate: " << target << " Found at index: " << result << endl;
    return 0;
}