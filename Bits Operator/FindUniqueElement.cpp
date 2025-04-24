#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[]={1,3,2,1,3,5,2,4,5,9,4};
    int n=11;
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    cout<<ans;
}