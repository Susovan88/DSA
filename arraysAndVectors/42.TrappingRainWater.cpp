#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height) {
        int n=height.size();
        // prev. greatest element array
        int prev[n];
        prev[0]=-1;
        int max=height[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
            if(max<height[i]) max=height[i];
        }
        // next greatest element array
        int next[n];
        next[n-1]=-1;
        max=height[n-1];
        for(int i=n-2;i>=0;i--){
            next[i]=max;
            if(max<height[i]) max=height[i];
        }
        // minimun array
        int mini[n];
        for(int i=0;i<n;i++){
            mini[i] = min(prev[i],next[i]);
        }
        // claculating water.
        int water=0;
        for(int i=0;i<n;i++){
            if(height[i]<mini[i]){
                water += (mini[i]-height[i]);
            }
        }
        return water;
    }
    
    int main(){
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  vector<int>v;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  int water=trap(v);
  cout<<"Trapping rain water is "<<water;
}
    
