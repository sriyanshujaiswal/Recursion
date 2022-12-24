#include<iostream>
using namespace std;

int sumofelement(int arr[], int size, int sum){
    // base cae
    if(size == 0)
        return sum;
    
    sum = sum + arr[0];
    return sumofelement(arr+1, size-1, sum);
    
}

int main(){

    int arr[5] ={3,2,5,1,6};
    int size=5;
    int sum= 0;
    int ans = sumofelement(arr, size, sum);
    cout<<"Sum :" << ans;
    return 0;
}