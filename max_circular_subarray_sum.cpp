#include<iostream>
#include<climits>
using namespace std;

int kadane(int arr[],int n){
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum<0){
            currSum=0;
        }
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}
//Max Subarray sum=Total sum of array - Sum of non contributing elements
//Reverse the sign of elements to get non-contributing elements
int main(){
    cout<<"Enter length of an array ";
    int n,nonwrapsum,wrapsum,totalsum=0;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of an array ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nonwrapsum=kadane(arr,n);  //WrapSum are the Contributing elements that are included
    for(int i=0;i<n;i++){   //To reverse the sign of elements
        totalsum+=arr[i];
        arr[i]=-arr[i];
    }
    wrapsum=totalsum+kadane(arr,n);//Sum of non-contributing elements
    cout<<"Max Sum Subarray is: "<<max(wrapsum,nonwrapsum);
    return 0;
}