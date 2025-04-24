#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void sort012(vector<int>& nums) {
    int n=nums.size();
    int n0=0,n1=0,n2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) n0++;
        else if(nums[i]==1) n1++;
        else n2++;
    }
    for(int i=0;i<n;i++){
        if(i<n0) nums[i]=0;
        else if(i<(n0+n1)) nums[i]=1;
        else nums[i]=2;
    }
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
  sort012(v);
  display(v);
}
