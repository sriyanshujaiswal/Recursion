#include<iostream>
using namespace std;

double moreprecision(int n, int precision, int sol){
    double factor = 1; 
    double ans = sol;
    for(int i=0; i< precision; i++){
        factor = factor / 10;
        for( int j = ans; j*j < n; j=j+factor){
            ans= j;
        }
    }
    return ans;
}

long long int sqrt(int n, int ans, int s , int e)
{
    int mid= s+ (e-s)/2;
    cout<< "Mid element is : "<< mid<< endl;
    // Base case 
    if(s>e)
        return -1;
    if(mid * mid == n)
        return mid;
    
    else if(mid*mid > n){
        return sqrt(n, ans, s, mid-1);
    }
    else {
        ans = mid;
        return sqrt( n, ans, mid+1 , e);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the Number :";
    cin>> n;
    int ans=-1;
    int s=0;
    int e= n;
    int sol= sqrt(n, ans, s, e);
    int answer = moreprecision( n , 3 , sol);
    cout<< "Answer is : "<< answer;
    cout<< endl;

    return 0;

}