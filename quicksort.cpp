#include<iostream>
using namespace std;

int partition(int *arr ,int s, int e){
    int pivot= arr[s];

    int cnt=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<= pivot){
            cnt++;
        }
    }

    // Place the pivot element
    int pivotIndex= s+ cnt;
    swap(arr[pivotIndex], arr[s]);

    //Left or right wala smbhal lena h
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i] <  pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quicksort(int *arr, int s, int e){

    // base case
    if(s>=e){
        return ;
    }
    
    int p =partition(arr, s, e);

    // Left wala array 
    quicksort(arr, s, p-1);

    // Right wala array
    quicksort(arr, p+1, e);

}

int main(){

    int arr[9] ={4,34,2,4,6,3,3,3,3};
    int n =9;
    
    quicksort(arr, 0, n-1);

    for(int i=0; i< n ; i++){
        cout<<arr[i]<< " ";
    }
    cout<< endl;

    return 0;
}
