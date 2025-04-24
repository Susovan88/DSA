#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int partition(vector<int>&arr,int si,int ei){

// step1 -> find pivot actual index . after that swap
    int pivotElement = arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivotElement) count++;
    }
    int pivortIdx=count+si;
    swap(arr[(si+ei)/2],arr[pivortIdx]);

// step2 -> placed the smaller element before and bigger element after the pivot.
    int i=si;
    int j= ei;
    while(i<pivortIdx && j>pivortIdx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivortIdx;
}
void quicksort(vector<int>&arr,int si,int ei){
    if(si>=ei) return;
    int pi=partition(arr,si,ei);

    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}
int main(){
    vector<int>arr={5,2,9,3,4,1,0,-2};
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
}