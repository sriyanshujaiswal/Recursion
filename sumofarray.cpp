#include<iostream>
using namespace std;

int sumofelement(int arr[], int size){
    // base cae
    if(size == 1)
        return arr[0];
    else{
        int sum = arr[0] + arr[1];
        arr[1] = sum;
       return sumofelement(arr+1, size-1);
    }
}

int main(){

    int arr[5] ={3,2,5,1,6};
    int size=5;
    int ans = sumofelement(arr, size);
    cout<<"Sum :" << ans;
    return 0;
}