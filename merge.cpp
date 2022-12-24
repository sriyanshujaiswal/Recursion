#include<iostream>
using namespace std;

void merge(int *arr , int s , int e)
{
    int  mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    
    // new array creation by heap memory
    int *first = new int [len1];
    int *second = new int [len2];

    // copying the array
    int mainarrayindex = s;
    for(int i=0 ; i< len1 ; i++)
    {
        first[i]= arr[mainarrayindex++];
    }

    mainarrayindex = mid+1;
    for(int i=0; i< len2; i++){
        second[i]= arr[mainarrayindex++];
    }

    // Merge Two sorted array
    int index1=0;
    int index2=0;
    mainarrayindex = s;
    while(index1<len1 && index2 < len2){
        if(first[index1]< second[index2]){
            arr[mainarrayindex++]= first[index1++];
        }
        else{
             arr[mainarrayindex++]= second[index2++];
        }
    }
    while(index1< len1){
        arr[mainarrayindex++]= first[index1++];
    }
    while(index2< len2)
    {
       arr[mainarrayindex++]= second[index2++]; 
    }
    delete []first;
    delete []second;
}

void mergesort(int *arr, int s, int e){
    
    // Base Case
    if(s>=e){
        return;
    }
    int mid= (s+e)/2;

    // Left Part Sort
    mergesort(arr, s, mid);

    // Right Part Sort
    mergesort(arr, mid+1, e);

    merge(arr, s, e);
    
}

int main(){

    int arr[9]={85,23,34,23,42,13,10,23,2};
    int n=9;
    mergesort(arr, 0 , n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<< endl;
    
    return 0;
}